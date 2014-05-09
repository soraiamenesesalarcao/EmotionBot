/*
 * WalkAndSpeakCompoundAction.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#include "WalkAndSpeakCompoundAction.h"

WalkAndSpeakCompoundAction::WalkAndSpeakCompoundAction() {
	this->parameter_destination = NULL;
	this->parameter_translation = NULL;
	this->phrase_to_say = NULL;
	//walk action
	walk_action = new WalkCompoundAction;
	walk_action->setParameterPosition(this->parameter_destination);
	walk_action->setParameterTrnaslation(this->parameter_translation);
	speak_simple_action = new SpeakSimpleAction;
	speak_simple_action->setParameterPhraseToSay(this->phrase_to_say);
	//add the actions
	this->abstract_actions.push_back(walk_action);
	this->abstract_actions.push_back(speak_simple_action);
	//info about the action
	this->action_description = "goes from point a to b while speaking";
	//parts used
	list<string> robot_parts_used_temp = walk_action->getRobotPartsUsed();
	this->robot_parts_used.merge(robot_parts_used_temp);
	robot_parts_used_temp = speak_simple_action->getRobotPartsUsed();
	this->robot_parts_used.merge(robot_parts_used_temp);
}

WalkAndSpeakCompoundAction::~WalkAndSpeakCompoundAction() {

}

list<SimpleActionExecution *> WalkAndSpeakCompoundAction::Analyze(){
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

void WalkAndSpeakCompoundAction::setParameterPosition(ParameterPosition * parameter_destination){
	this->parameter_destination = parameter_destination;
}

ParameterPosition * WalkAndSpeakCompoundAction::getParameterPosition(){
	return this->parameter_destination;
}

void WalkAndSpeakCompoundAction::setParameterTrnaslation(ParameterTranslation * parameter_translation){
	this->parameter_translation = parameter_translation;
}

ParameterTranslation * WalkAndSpeakCompoundAction::getParameterTranslation(){
	return this->parameter_translation;
}

void WalkAndSpeakCompoundAction::setParameterPhraseToSay(string *phrase_to_say){
	this->phrase_to_say = phrase_to_say;
}

string *WalkAndSpeakCompoundAction::getParameterPhraseToSay(){
	return this->phrase_to_say;
}
