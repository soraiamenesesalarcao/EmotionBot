/*
 * OscillateShoulderDescription.cpp
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#include "OscillateShoulderDescription.h"

OscillateShoulderDescription::OscillateShoulderDescription() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->action_name = "oscillate_shoulder";
	this->robot_parts_used.push_back("shoulder");
}

OscillateShoulderDescription::~OscillateShoulderDescription() {
	delete this->parameter_destination;
	delete this->parameter_translation;
}
list<SimpleActionExecution *> OscillateShoulderDescription::Analyze(void){
	list<SimpleActionExecution *> temp;
	OscillateShoulderExecution *oscillate_execution = new OscillateShoulderExecution;
	oscillate_execution->setParameterDestination(this->parameter_destination);
	if(this->parameter_translation != NULL){
		oscillate_execution->setParameterTranslation(this->parameter_translation);
	}
	temp.push_back(oscillate_execution);
	return temp;
}
void OscillateShoulderDescription::setParameterPointPosition(PointPositionParameter * parameter_destination){
	this->parameter_destination = parameter_destination;
}
PointPositionParameter * OscillateShoulderDescription::getParameterPosition(){
	return this->parameter_destination;
}
void OscillateShoulderDescription::setParameterTranslation(ParameterTranslation * parameter_translation){
	this->parameter_translation = parameter_translation;
}
ParameterTranslation * OscillateShoulderDescription::getParameterTranslation(){
	return this->parameter_translation;
}

