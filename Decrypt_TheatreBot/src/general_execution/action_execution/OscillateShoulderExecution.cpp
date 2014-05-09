/*
 * OscillateShoulderExecution.cpp
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#include "OscillateShoulderExecution.h"

OscillateShoulderExecution::OscillateShoulderExecution() {
	this->parameter_destination = NULL;
	this->action_name = "oscillate_shoulder";
	this->type_action = TypeActionTrajectory;
}

OscillateShoulderExecution::~OscillateShoulderExecution() {
	delete this->parameter_destination;
}

bool OscillateShoulderExecution::executeAction(string platform){
	bool result=false;
	if(platform == "triskar_big"){


	}else if(platform == "triskar_small"){
		cout<<"executing move body"<<endl;
	}
	return result;

}
void OscillateShoulderExecution::setParameterDestination(PointPositionParameter *parameter_destination){
	this->parameter_destination = parameter_destination;
}
PointPositionParameter* OscillateShoulderExecution::getParameterDestination(){
	return this->parameter_destination;
}
