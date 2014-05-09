/*
 * Move.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: julian
 */

#include "MoveBodyExecution.h"

MoveBodyExecution::MoveBodyExecution() {
	this->parameter_destination = NULL;
	this->action_name = "move_body";
	this->type_action = TypeActionTrajectory;
}

MoveBodyExecution::~MoveBodyExecution() {
	delete this->parameter_destination;
}

/**
 * This command knows which driver execute to perform the action in the correct platform
 */
bool MoveBodyExecution::executeAction(string platform){
	bool result=false;
	if(platform == "triskar_big"){


	}else if(platform == "triskar_small"){
		cout<<"executing move body"<<endl;
	}
	return result;
}

void MoveBodyExecution::setParameterDestination(ParameterPosition *parameter_destination){
	this->parameter_destination = parameter_destination;
}
ParameterPosition* MoveBodyExecution::getParameterDestination(){
	return this->parameter_destination;
}
