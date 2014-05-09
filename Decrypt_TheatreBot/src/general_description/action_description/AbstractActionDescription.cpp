///////////////////////////////////////////////////////////
//  AbstractAction.cpp
//  Implementation of the Class AbstractAction
//  Created on:      01-abr-2014 05:53:23 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#include "AbstractActionDescription.h"


AbstractActionDescription::AbstractActionDescription(){

}



AbstractActionDescription::~AbstractActionDescription(){
	//Delete action parameters
	for(vector<ParameterValue *>::iterator it = action_parameters.begin();
			it != action_parameters.end(); it++){
		delete *it;
	}
}


string AbstractActionDescription::getActionDescription(){

	return  this->action_description;
}


string AbstractActionDescription::getActionName(){

	return  this->action_name;
}


list<string> AbstractActionDescription::getRobotPartsUsed(){

	return  this->robot_parts_used;
}


void AbstractActionDescription::addRobotPartUsed(string part_used){

	this->robot_parts_used.push_back(part_used);
}

void AbstractActionDescription::setRobotPartsUsed(list<string> robot_parts_used){

	this->robot_parts_used = robot_parts_used;
}


void AbstractActionDescription::setActionDescription(string description){

	this->action_description = description;
}


void AbstractActionDescription::setActionName(string action_name){

	this->action_name = action_name;
}


vector<ParameterValue *> AbstractActionDescription::getActionParameters(){

	return  this->action_parameters;
}


void AbstractActionDescription::setActionParameter(vector<ParameterValue *> action_parameters){

	this->action_parameters = action_parameters;
}

void AbstractActionDescription::addActionParameter(ParameterValue * action_parameter){
	this->action_parameters.push_back(action_parameter);
}
