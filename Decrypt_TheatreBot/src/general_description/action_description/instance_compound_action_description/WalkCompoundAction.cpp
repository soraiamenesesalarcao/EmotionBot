/*
 * WalkCompoundAction.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#include "WalkCompoundAction.h"

WalkCompoundAction::WalkCompoundAction() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->reduce_factor_shoulder =  4.0;
	//simple action move body
	move_body_simple_action =  new MoveBodySimpleActionDescription;
	move_body_simple_action->setParameterPosition(this->parameter_destination);
	move_body_simple_action->setParameterTrnaslation(this->parameter_translation);
	//Simple action move shoulder
	oscillate_shoulder_simple_action = new OscillateShoulderDescription;
	PointPositionParameter * move_shoulder_parameter = new PointPositionParameter;
	//Parameter of the amplitude
	move_shoulder_parameter->setPointPosition(0.2,0.0,0.0);
	oscillate_shoulder_simple_action->setParameterPointPosition(move_shoulder_parameter);
	//Info of the action
	this->action_name = "walk";
	this->action_description = "This actions moves one robot from point A to point B";
	this->abstract_actions.push_back(oscillate_shoulder_simple_action);
	this->abstract_actions.push_back(move_body_simple_action);

	//get the part used by the other actions
	list<string> robot_parts_used_temp = move_body_simple_action->getRobotPartsUsed();
	this->robot_parts_used.merge(robot_parts_used_temp);
	robot_parts_used_temp = oscillate_shoulder_simple_action->getRobotPartsUsed();
	this->robot_parts_used.merge(robot_parts_used_temp);

}

WalkCompoundAction::~WalkCompoundAction() {
}
list<SimpleActionExecution *> WalkCompoundAction::Analyze(){
	list<SimpleActionExecution *> temp;
	for(vector<AbstractActionDescription *>::iterator it = abstract_actions.begin();
			it != abstract_actions.end(); ++it){
		list<SimpleActionExecution *> t = (*it)->Analyze();
		temp.merge(t);
	}
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	return temp;
}
void WalkCompoundAction::setParameterPosition(ParameterPosition * parameter_destination){

	this->parameter_destination = parameter_destination;
}
ParameterPosition * WalkCompoundAction::getParameterPosition(){

	return this->parameter_destination;
}
void WalkCompoundAction::setParameterTrnaslation(ParameterTranslation * parameter_translation){
	this->parameter_translation = parameter_translation;
	this->reduceTranslationParameterShoulder();
}
void WalkCompoundAction::reduceTranslationParameterShoulder(){
	if(typeid(this->parameter_translation).name()
			==typeid(ParameterVelocity).name()){
		ParameterVelocity * temp_parameter_velocity = dynamic_cast<ParameterVelocity *> (this->parameter_translation);
		ParameterVelocity * parameter_shoulder = new ParameterVelocity;
		parameter_shoulder->setVelocity(temp_parameter_velocity->getVelocityX()/this->reduce_factor_shoulder,
				temp_parameter_velocity->getVelocityY()/this->reduce_factor_shoulder,
				temp_parameter_velocity->getVelocityTheta()/this->reduce_factor_shoulder);
		oscillate_shoulder_simple_action->setParameterTranslation(parameter_shoulder);
	}else if(typeid(this->parameter_translation).name()
			==typeid(ParameterTime).name()){
		ParameterTime * temp_parameter_time = dynamic_cast<ParameterTime *> (this->parameter_translation);
		ParameterTime * parameter_shoulder = new ParameterTime;
		parameter_shoulder->setTimeValue(temp_parameter_time->getTimeValue()/this->reduce_factor_shoulder);
		oscillate_shoulder_simple_action->setParameterTranslation(parameter_shoulder);
	}else if(typeid(this->parameter_translation).name()
			==typeid(ParameterAcceleration).name()){
		ParameterAcceleration * temp_parameter_acceleration = dynamic_cast<ParameterAcceleration *> (this->parameter_translation);
		ParameterAcceleration * parameter_shoulder = new ParameterAcceleration;
		parameter_shoulder->setAcceleration(temp_parameter_acceleration->getAccelerationX()/this->reduce_factor_shoulder,
				temp_parameter_acceleration->getAccelerationY()/this->reduce_factor_shoulder,
				temp_parameter_acceleration->getAccelerationTheta()/this->reduce_factor_shoulder);
		oscillate_shoulder_simple_action->setParameterTranslation(parameter_shoulder);
	}
}
ParameterTranslation * WalkCompoundAction::getParameterTranslation(){

	return this->parameter_translation;
}
float WalkCompoundAction::getShoulderReduceFactor(){
	return this->reduce_factor_shoulder;
}
void WalkCompoundAction::setShoulderReduceFactor(float reduce_factor){
	this->reduce_factor_shoulder = reduce_factor;
}

