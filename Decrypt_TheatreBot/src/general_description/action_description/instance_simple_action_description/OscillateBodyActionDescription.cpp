/*
 * OscillateBodyActionDescription.cpp
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#include "OscillateBodyActionDescription.h"

OscillateBodyActionDescription::OscillateBodyActionDescription() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->action_name = "oscillate_body";
	this->robot_parts_used.push_back("legs");
}

OscillateBodyActionDescription::~OscillateBodyActionDescription() {
	delete this->parameter_destination;
	delete this->parameter_translation;
}
list<SimpleActionExecution *> OscillateBodyActionDescription::Analyze(void){
	list<SimpleActionExecution *> temp;
	OscillateBodyExecution *oscillate_execution = new OscillateBodyExecution;
	oscillate_execution->setParameterDestination(this->parameter_destination);
	if(this->parameter_translation != NULL){
		oscillate_execution->setParameterTranslation(this->parameter_translation);
	}
	temp.push_back(oscillate_execution);
	return temp;
}
void OscillateBodyActionDescription::setParameterPointPosition(PointPositionParameter * parameter_destination){

	this->parameter_destination = parameter_destination;
}
PointPositionParameter * OscillateBodyActionDescription::getParameterPosition(){

	return this->parameter_destination;
}
void OscillateBodyActionDescription::setParameterTrnaslation(ParameterTranslation * parameter_translation){

	this->parameter_translation = parameter_translation;
}
ParameterTranslation * OscillateBodyActionDescription::getParameterTranslation(){

	return this->parameter_translation;
}

