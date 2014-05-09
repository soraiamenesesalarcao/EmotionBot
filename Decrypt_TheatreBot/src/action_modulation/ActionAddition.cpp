/*
 * ActionAddition.cpp
 *
 *  Created on: May 2, 2014
 *      Author: julian
 */

#include "ActionAddition.h"

ActionAddition::ActionAddition() {
	// TODO Auto-generated constructor stub

}

ActionAddition::~ActionAddition() {
	// TODO Auto-generated destructor stub
}

void ActionAddition::addAdditionalSimpleActions(string emotion_and_action,list<SimpleActionExecution *> *list_simple_action,
		map<string,EmotionProfile *> emotions_profile){
	//Get the list of missing actions
	list<string> list_missing_actions;
	//Gets the description of the emotion
	EmotionProfile * temp_emotion_description = emotions_profile[emotion_and_action];
	list_missing_actions =
			searchMissingActions(temp_emotion_description->getEmotionProfileActions(),*list_simple_action);
	//Instance of the missing actions
	instanceMissingActions(list_missing_actions,list_simple_action);
}

void ActionAddition::instanceMissingActions(list<string> list_missing_actions,
		list<SimpleActionExecution *> *list_simple_action){
	for(list<string>::iterator it = list_missing_actions.begin();
			it != list_missing_actions.end(); it++){
		list_simple_action->push_back(instanceMissingAction(*it));
	}
}

SimpleActionExecution * ActionAddition::instanceMissingAction(string missing_action_name){
	SimpleActionExecution * temp_action_execution = NULL;
	if(missing_action_name=="move_shoulder"){
		temp_action_execution = new MoveShoulderExecution;
	}else if(missing_action_name=="move_body"){
		temp_action_execution = new MoveBodyExecution;
	}else if(missing_action_name=="speak"){
		temp_action_execution = new SpeakExecution;
	}else if(missing_action_name=="oscillate_body"){
		temp_action_execution = new OscillateBodyExecution;
	}else if(missing_action_name=="oscillate_shoulder"){
		temp_action_execution = new OscillateShoulderExecution;
	}
	return temp_action_execution;
}

list<string> ActionAddition::searchMissingActions(vector<ActionChanges *> action_changes, list<SimpleActionExecution *> list_simple_action){
	list<string> temp_missing_actions;

	for(vector<ActionChanges *>::iterator it_action = action_changes.begin();
			it_action != action_changes.end(); it_action++){
		if(!isTheAction((*it_action)->getActionChangesName(), list_simple_action)){
			temp_missing_actions.push_back((*it_action)->getActionChangesName());
		}
	}
	return temp_missing_actions;
}

bool ActionAddition::isTheAction(string action_name, list<SimpleActionExecution *> list_simple_action){
	for(list<SimpleActionExecution *>::iterator it_list = list_simple_action.begin();
			it_list != list_simple_action.end(); it_list++){
		if(action_name == (*it_list)->getActionName()){
			return true;
		}
	}
	return false;
}
