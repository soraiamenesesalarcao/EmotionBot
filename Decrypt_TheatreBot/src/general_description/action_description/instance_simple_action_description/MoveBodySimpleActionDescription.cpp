/*
 * MoveSimpleActionDescription.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: julian
 */

#include "MoveBodySimpleActionDescription.h"

MoveBodySimpleActionDescription::MoveBodySimpleActionDescription() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->action_name = "move_body";
	this->robot_parts_used.push_back("legs");
}

MoveBodySimpleActionDescription::~MoveBodySimpleActionDescription() {
	delete this->parameter_destination;
	delete this->parameter_translation;
}

list<SimpleActionExecution *> MoveBodySimpleActionDescription::Analyze(void){
	list<SimpleActionExecution *> temp;
	MoveBodyExecution *move_execution = new MoveBodyExecution;
	move_execution->setParameterDestination(this->parameter_destination);
	if(this->parameter_translation != NULL){
		move_execution->setParameterTranslation(this->parameter_translation);
	}
	temp.push_back(move_execution);
	return temp;
}


void MoveBodySimpleActionDescription::setParameterPosition(ParameterPosition * parameter_destination){
	this->parameter_destination = parameter_destination;
}
ParameterPosition * MoveBodySimpleActionDescription::getParameterPosition(){
	return this->parameter_destination;
}
void MoveBodySimpleActionDescription::setParameterTrnaslation(ParameterTranslation * parameter_translation){
	this->parameter_translation = parameter_translation;
}
ParameterTranslation * MoveBodySimpleActionDescription::getParameterTranslation(){
	return this->parameter_translation;
}
