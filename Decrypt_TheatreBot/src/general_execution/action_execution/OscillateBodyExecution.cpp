/*
 * OscillateBodyExecution.cpp
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#include "OscillateBodyExecution.h"

OscillateBodyExecution::OscillateBodyExecution() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->action_name = "oscillate_body";
	this->type_action = TypeActionTrajectory;
}

OscillateBodyExecution::~OscillateBodyExecution() {
	delete this->parameter_destination;
	delete this->parameter_translation;
}
bool OscillateBodyExecution::executeAction(string platform){
	bool result = false;
	if(platform == "triskar_big"){


	}else if(platform == "triskar_small"){
		cout<<"executing move body"<<endl;
	}


	return result;
}
void OscillateBodyExecution::setParameterDestination(PointPositionParameter *parameter_destination){
	this->parameter_destination = parameter_destination;
}
PointPositionParameter* OscillateBodyExecution::getParameterDestination(){
	return this->parameter_destination;
}

