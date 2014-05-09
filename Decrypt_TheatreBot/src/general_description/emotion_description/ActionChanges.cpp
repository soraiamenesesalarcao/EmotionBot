///////////////////////////////////////////////////////////
//  ActionChanges.cpp
//  Implementation of the Class ActionChanges
//  Created on:      01-abr-2014 05:53:23 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#include "ActionChanges.h"


ActionChanges::ActionChanges(){
	type_action_emotion = TypeActionEmotionChangeUnknown;
}



ActionChanges::~ActionChanges(){
	for(vector<EmotionParameter *>::iterator it = this->action_changes_parameters.begin();
			it != this->action_changes_parameters.end(); it++){
		delete *it;
	}
}





string ActionChanges::getActionChangesName(){

	return  action_changes_action;
}


void ActionChanges::setActionChangesName(string action_changes_name){

	this->action_changes_action = action_changes_name;
}


vector<EmotionParameter *> ActionChanges::getActionChangesParameteres(){

	return  action_changes_parameters;
}


void ActionChanges::setActionChangesParameter(vector<EmotionParameter *> action_changes_parameters){

	this->action_changes_parameters = action_changes_parameters;
}

void ActionChanges::setTypeActionEmotion(TypeActionEmotionChange type_action_emotion){
	this->type_action_emotion = type_action_emotion;
}

TypeActionEmotionChange ActionChanges::getTypeActionEmotion(){

	return this->type_action_emotion;
}


void ActionChanges::addActioChangesParameter(EmotionParameter * emotion_parameter){
	this->action_changes_parameters.push_back(emotion_parameter);
}
