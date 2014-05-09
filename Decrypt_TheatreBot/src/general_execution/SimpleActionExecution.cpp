/*
 * SimpleActionExecution.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: julian
 */

#include "SimpleActionExecution.h"

SimpleActionExecution::SimpleActionExecution() {
	type_action = TypeActionUnknown;
}

SimpleActionExecution::~SimpleActionExecution() {

}

TypeAction SimpleActionExecution::getSimpleActionType(){
	return this->type_action;
}


void SimpleActionExecution::setSimpleActionType(TypeAction type_action){
	this->type_action = type_action;
}

void SimpleActionExecution::setActionName(string action_name){
	this->action_name = action_name;
}
string SimpleActionExecution::getActionName(){
	return this->action_name;
}
