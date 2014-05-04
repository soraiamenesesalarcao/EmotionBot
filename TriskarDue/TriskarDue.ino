//This get faster the info from the pins
#include <digitalWriteFast.h>
//Need it to calculate velocity each x time
#include <TimerOne.h>
//PID
#include <PID_v1.h>
//Triskar libraries
#include <string.h>
#include <Triskar.h>
#include <MC33887.h>
//Servo motors
#include <Servo.h>
//#include <SerialCommand.h>
//This libraries are for arduino communication
#include <ros.h>
#include <std_msgs/String.h>
//This libraries are for sensor information
#include <ros/time.h>
#include <sensor_msgs/Range.h>
//Robot position
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>

/*Velocity*/
/*12V brushed DC motor with a 29:1 metal gearbox and an integrated quadrature encoder that provides a resolution of 64 counts per revolution of the motor shaft, which corresponds to 1856 counts per revolution of the gearbox�s output shaft.*/
const float countsMotor = 1856.0;
//it is diveded by 2 because is just getting the upper part
const float countsCode = (float)countsMotor/2.0;
// set a timer of length 25000 microseconds (or 0.025 sec - or 40Hz )
const float timeCalculation = 25000.0;
const int timePID=(int) timeCalculation/10000.0;
const float timeSecond = (float)timeCalculation/1000000.0;//second
const float radio = 0.035;//meters
const double factorDistance = (double)2*PI*radio/countsCode;
const float factorAngular = 2*PI/countsCode/timeSecond;
float distanceMotor1 = 0.0;
float distanceMotor1T = 0.0;
float distanceMotor2 = 0.0;
float distanceMotor2T = 0.0;
float distanceMotor3 = 0.0;
float distanceMotor3T = 0.0;
double angularVelocityMotor1 = 0.0;
double angularVelocityMotor2 = 0.0;
double angularVelocityMotor3 = 0.0;
double velocityMotor1 = 0.0;
double velocityMotor2 = 0.0;
double velocityMotor3 = 0.0;
double outputMotor1PID = 0.0;
double outputMotor2PID = 0.0;
double outputMotor3PID = 0.0;
double setPointMotor1 = 0.0;
double setPointMotor2 = 0.0;
double setPointMotor3 = 0.0;

/*PID motors*/
PID motor1PID;
PID motor2PID;
PID motor3PID;
/*Motor 1*/
//Definition of the pins which handles the interruptions
#define motor1EncoderIsReversed
#define motor1_InterruptA 0 //2
#define motor1_PinA 2
#define motor1_InterruptB 1 //3
#define motor1_PinB 3
volatile bool motor1EncoderSetA;
volatile bool motor1EncoderSetB;
volatile long motor1EncoderTicks = 0L;

/*Motor 2*/
//Definition of the pins which handles the interruptions
#define motor2EncoderIsReversed
#define motor2_InterruptA 2//21
#define motor2_PinA 21
#define motor2_InterruptB 3//20
#define motor2_PinB 20
volatile bool motor2EncoderSetA;
volatile bool motor2EncoderSetB;
volatile long motor2EncoderTicks = 0L;


/*Motor 3*/
//Definition of the pins which handles the interruptions
#define motor3EncoderIsReversed
#define motor3_InterruptA 4//19
#define motor3_PinA 19
#define motor3_InterruptB 5//18
#define motor3_PinB 18
volatile bool motor3EncoderSetA;
volatile bool motor3EncoderSetB;
volatile long motor3EncoderTicks = 0L;

/*Servo Motors*/
Servo leftServo;//pin 4
Servo centralServo;//pin 5
Servo rightServo;//pin 6

/*Triskar*/
MC33887 m1(8, 22, 23);//(pwd, en1, en2)
MC33887 m2(9, 24, 25);//(pwd, en1, en2)
MC33887 m3(10, 26, 27);//(pwd, en1, en2)
Triskar triskar(m1, m2, m3);



/*Ros*/
ros::NodeHandle  nh;
//This is to recieve the information
std_msgs::String velocity;
//This is to send the information
std_msgs::String distance;

sensor_msgs::Range range_msg;

ros::Publisher pub_range( "range_data_triskar", &range_msg);

const int analog_pin = 0;
unsigned long range_timer;


geometry_msgs::Pose postion_msg;
ros::Publisher positionTriskar("position_dataTriskar", &postion_msg);

/*
 * getRange() - samples the analog input from the ranger
 * and converts it into meters.  
 */
float getRange(int pin_num){
    float sample;
    // Get data
    sample = analogRead(pin_num)*0.0048828125;
    // if the ADC reading is too low, 
    //   then we are really far away from anything
    float distance = 65.0*pow(sample, -1.10); 
    return distance; //convert to meters
}

void messageCb(const geometry_msgs::Twist& msg){
  //sum_msg.position.x = msg.linear.x;
  //sum_msg.position.y = msg.linear.y;
  //sum_msg.position.z = msg.angular.z;
  triskar.run(msg.linear.x, msg.linear.y, msg.angular.z);
  setPointMotor1=triskar.getM1();
  setPointMotor2=triskar.getM2();
  setPointMotor3=triskar.getM3();
  postion_msg.position.x = triskar.getM1();
  postion_msg.position.y = triskar.getM2();
  postion_msg.position.z = triskar.getM3();
  postion_msg.orientation.x = velocityMotor1;
  postion_msg.orientation.y = velocityMotor2;
  postion_msg.orientation.z = velocityMotor3;
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<geometry_msgs::Twist> setVelocity("velocity_triskar",messageCb);

/*
 x=1 servo to control
 y= desire angle
 z= oscilation
*/
void servo_cb( const geometry_msgs::Vector3& cmd_msg){
  if(cmd_msg.x==1){
    leftServo.write(cmd_msg.y);
  }else if(cmd_msg.x==2){
    centralServo.write(cmd_msg.y);
  }else if(cmd_msg.x==3){
    rightServo.write(cmd_msg.y);
  }
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<geometry_msgs::Vector3> setServo("servo_triskar", servo_cb);

//SerialCommand sCmd;
float setpoint[3] = {0.0, 0.0, 0.0}; // setpoint[strafe, forward, angular]

unsigned long time = 0L;

char frameid[] = "/ir_ranger";


void setup()
{
	/*Serial*/
	//Serial.begin(115200);
        
        
        /*Ros*/
        //nh.getHardware()->setBaud(11520);
        //Distance
        nh.initNode();
        nh.advertise(pub_range);
        
        range_msg.radiation_type = sensor_msgs::Range::INFRARED;
        range_msg.header.frame_id =  frameid;
        range_msg.field_of_view = 0.01;
        range_msg.min_range = 0.2;
        range_msg.max_range = 1.5; 
 
        //position
         pinMode(13, OUTPUT); 
        //nh2.initNode();
        nh.subscribe(setVelocity);
        nh.advertise(positionTriskar);  
        nh.subscribe(setServo);    
	/*PID*/
	//Motor 1
	motor1PID.setupPID(&angularVelocityMotor1, &outputMotor1PID, &setPointMotor1,5,1,0.0000001, DIRECT);
	motor1PID.SetOutputLimits(-255,255);
	motor1PID.SetMode(AUTOMATIC);
	motor1PID.SetSampleTime(timePID);
	//Motor 2
	motor2PID.setupPID(&angularVelocityMotor2, &outputMotor2PID, &setPointMotor2,5,1,0.0000001, DIRECT);
	motor2PID.SetOutputLimits(-255,255);
	motor2PID.SetMode(AUTOMATIC);
	motor2PID.SetSampleTime(timePID);
	//Motor 3
	motor3PID.setupPID(&angularVelocityMotor3, &outputMotor3PID, &setPointMotor3,5,1,0.0000001, DIRECT);
	motor3PID.SetOutputLimits(-255,255);
	motor3PID.SetMode(AUTOMATIC);
	motor3PID.SetSampleTime(timePID);
	/*Triskar*/
	triskar.stop();
	// Setup callbacks for SerialCommand commands
	//sCmd.addCommand("r", run_cb);
	//sCmd.addCommand("s", stop_cb);
	//sCmd.setDefaultHandler(invalid);
	/*Timer Interrupt*/
	Timer1.initialize(timeCalculation);
	Timer1.attachInterrupt(calculateVelocityMotors);
	/*Quadrature encoders*/
	//Motor 1
	pinMode(motor1_PinA, INPUT);
	pinMode(motor1_PinB, INPUT);
	attachInterrupt(motor1_InterruptA, HandleMotor1InterruptA, RISING);
	attachInterrupt(motor1_InterruptB, HandleMotor1InterruptB, RISING);
	//Motor 2
	pinMode(motor2_PinA, INPUT);
	pinMode(motor2_PinB, INPUT);
	attachInterrupt(motor2_InterruptA, HandleMotor2InterruptA, RISING);
	attachInterrupt(motor2_InterruptB, HandleMotor2InterruptB, RISING);
	//Motor 1
	pinMode(motor3_PinA, INPUT);
	pinMode(motor3_PinB, INPUT);
	attachInterrupt(motor3_InterruptA, HandleMotor3InterruptA, RISING);
	attachInterrupt(motor3_InterruptB, HandleMotor3InterruptB, RISING);

        /*Servo*/
        leftServo.attach(4);
        leftServo.write(45);
        centralServo.attach(5);
        centralServo.write(90);
        rightServo.attach(6);
        rightServo.write(45);
}

void loop()
{
 
     // publish the range value every 50 milliseconds
     //   since it takes that long for the sensor to stabilize
     if ( (millis()-range_timer) > 50){
       range_msg.range = getRange(analog_pin);
       range_msg.header.stamp = nh.now();
       pub_range.publish(&range_msg);
       range_timer =  millis() + 50;
     }
     positionTriskar.publish(&postion_msg);
     nh.spinOnce();
     //nh2.spinOnce();
     delay(100); 
    /*
    Still missing configure this
      chatter.publish( &str_msg ); //This publish the info
      nh.spinOnce(); //This send the information
      delay(10); //Delay should be each 100 mili secons
    */
	/*sCmd.readSerial();     // We don't do much, just process serial commands
	if(millis()-time>=500){
		time = millis();
		Serial.print(angularVelocityMotor1);
		Serial.print("\t s ");
		Serial.print(setPointMotor1);
		Serial.print("\t o ");
		Serial.print(outputMotor1PID);
		Serial.print("\t v");
		Serial.print(velocityMotor1);
		Serial.print("\n");
	}*/
}

/*Callback functions serial*/
/*Using ros this commands are not necessary more*/
/*void stop_cb() {
	triskar.run(0,0,0);
	triskar.stop();
	setPointMotor1=triskar.getM1();
	setPointMotor2=triskar.getM2();
	setPointMotor3=triskar.getM3();
}
void run_cb() {
  for (int i = 0; i < 3; i++) {
    char *arg;
    arg = sCmd.next();    // Get the next argument from the SerialCommand object buffer
    if (arg != NULL) {    // As long as it existed, take it
      setpoint[i] = atof(arg);
    } else {
      setpoint[i] = 0;
    }
  }
  triskar.run(setpoint[0], setpoint[1], setpoint[2]);
  setPointMotor1=triskar.getM1();
  setPointMotor2=triskar.getM2();
  setPointMotor3=triskar.getM3();
//  Serial.print(setpoint[0]);
//  Serial.print(" ");
//  Serial.print(setpoint[1]);
//  Serial.print(" ");
//  Serial.println(setpoint[2]);
}

void invalid(const char *command) {
  Serial.println("Invalid command");
}*/


/*Timer Function*/

void calculateVelocityMotors(){;
	//Save the info and reset the counter
	distanceMotor1T=motor1EncoderTicks;
	motor1EncoderTicks=0;
	distanceMotor2T=motor2EncoderTicks;
	motor2EncoderTicks=0;
	distanceMotor3T=motor3EncoderTicks;
	motor3EncoderTicks=0;
	//Calculate distance
	angularVelocityMotor1 = distanceMotor1T;
	angularVelocityMotor2 = distanceMotor2T;
	angularVelocityMotor3 = distanceMotor3T;
	distanceMotor1T*=factorDistance;//meters
	distanceMotor2T*=factorDistance;
	distanceMotor3T*=factorDistance;
	//Update total distance of each wheel
	distanceMotor1+=distanceMotor1T;
	distanceMotor2+=distanceMotor2T;
	distanceMotor3+=distanceMotor3T;
	//Calculate angular velocity
	angularVelocityMotor1= angularVelocityMotor1*factorAngular;
	angularVelocityMotor2= angularVelocityMotor2*factorAngular; 
	angularVelocityMotor3= angularVelocityMotor3*factorAngular; 
	//Calculate lineal velocity
	velocityMotor1= (double)distanceMotor1T/timeSecond;
	velocityMotor2= (double)distanceMotor2T/timeSecond;
	velocityMotor3= (double)distanceMotor3T/timeSecond;

	//PID
	motor1PID.Compute();
        motor2PID.Compute();
        motor3PID.Compute();
	triskar.runM((float)outputMotor1PID,(float)outputMotor2PID,(float)outputMotor3PID);
}

/*Quadrature functions*/
//Motor 1
void HandleMotor1InterruptA(){
	motor1EncoderSetB = digitalReadFast(motor1_PinB);
	#ifdef motor1EncoderIsReversed
	motor1EncoderTicks -= motor1EncoderSetB?-1:+1;
	#else
	motor1EncoderTicks += motor1EncoderSetB?-1:+1;
	#endif
}

void HandleMotor1InterruptB(){
	motor1EncoderSetA = digitalReadFast(motor1_PinA);
	#ifdef motor1EncoderIsReversed
	motor1EncoderTicks += motor1EncoderSetA?-1:+1;
	#else
	motor1EncoderTicks -= motor1EncoderSetA?-1:+1;
	#endif
}

//Motor 2
void HandleMotor2InterruptA(){
	motor2EncoderSetB = digitalReadFast(motor2_PinB);
	#ifdef motor2EncoderIsReversed
	motor2EncoderTicks -= motor2EncoderSetB?-1:+1;
	#else
	motor2EncoderTicks += motor2EncoderSetB?-1:+1;
	#endif
}

void HandleMotor2InterruptB(){
	motor2EncoderSetA = digitalReadFast(motor2_PinA);
	#ifdef motor2EncoderIsReversed
	motor2EncoderTicks += motor2EncoderSetA?-1:+1;
	#else
	motor2EncoderTicks -= motor2EncoderSetA?-1:+1;
	#endif
}

//Motor 3
void HandleMotor3InterruptA(){
	motor3EncoderSetB = digitalReadFast(motor3_PinB);
	#ifdef motor3EncoderIsReversed
	motor3EncoderTicks -= motor3EncoderSetB?-1:+1;
	#else
	motor3EncoderTicks += motor3EncoderSetB?-1:+1;
	#endif
}

void HandleMotor3InterruptB(){
	motor3EncoderSetA = digitalReadFast(motor3_PinA);
	#ifdef motor3EncoderIsReversed
	motor3EncoderTicks += motor3EncoderSetA?-1:+1;
	#else
	motor3EncoderTicks -= motor3EncoderSetA?-1:+1;
	#endif
}
