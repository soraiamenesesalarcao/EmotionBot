/*
 * MoveShoulderSimpleActionDescription.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: julian
 */

#include "MoveShoulderSimpleActionDescription.h"

MoveShoulderSimpleActionDescription::MoveShoulderSimpleActionDescription() {
	this->parameter_position = NULL;
	this->parameter_translation = NULL;
	this->action_name = "move_shoulder";
	this->robot_parts_used.push_back("shoulder");
}

MoveShoulderSimpleActionDescription::~MoveShoulderSimpleActionDescription() {
	delete this->parameter_position;
	delete this->parameter_translation;
}

list<SimpleActionExecution *> MoveShoulderSimpleActionDescription::Analyze(){
	list<SimpleActionExecution *> temp;
	MoveShoulderExecution *shoulder_execution = new MoveShoulderExecution;
	shoulder_execution->setParameterPointPosition(this->parameter_position);
	if(this->parameter_translation != NULL)
		shoulder_execution->setParameterTranslation(this->parameter_translation);
	temp.push_back(shoulder_execution);
	return temp;
}
void MoveShoulderSimpleActionDescription::setParameterPointPosition(PointPositionParameter * parameter_position){
	this->parameter_position = parameter_position;
}
PointPositionParameter * MoveShoulderSimpleActionDescription::getParameterPosition(){
	return this->parameter_position;
}
void MoveShoulderSimpleActionDescription::setParameterTranslation(ParameterTranslation  * parameter_translation){
	this->parameter_translation = parameter_translation;
}
ParameterTranslation  * MoveShoulderSimpleActionDescription::getParameterTranslation(){
	return this->parameter_translation;
}
