/*
 * MoveShoulderExecution.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: julian
 */

#include "MoveShoulderExecution.h"

MoveShoulderExecution::MoveShoulderExecution() {
	this->parameter_position = NULL;
	this->parameter_translation = NULL;
	this->action_name = "move_shoulder";
	this->type_action = TypeActionTrajectory;
}

MoveShoulderExecution::~MoveShoulderExecution() {
	delete this->parameter_position;
	if(this->parameter_translation!=NULL){
		delete this->parameter_translation;
	}
}


bool MoveShoulderExecution::executeAction(string platform){
	bool result=false;
	if(platform == "triskar_big"){

	}else if(platform == "triskar_small"){
		cout<<"executing move shoulder"<<endl;
	}
	return result;
}
void MoveShoulderExecution::setParameterPointPosition(PointPositionParameter * parameter_position){
	this->parameter_position = parameter_position;
}
PointPositionParameter * MoveShoulderExecution::getParameterPosition(){
	return this->parameter_position;
}
