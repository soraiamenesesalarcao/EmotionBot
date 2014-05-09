/*
 * ActionModification.cpp
 *
 *  Created on: May 2, 2014
 *      Author: julian
 */

#include "ActionModification.h"

ActionModification::ActionModification() {
	// TODO Auto-generated constructor stub

}

ActionModification::~ActionModification() {
	// TODO Auto-generated destructor stub
}

void ActionModification::modifySimpleActions(string emotion_and_action, list<SimpleActionExecution *> *list_simple_action ,
		map<string,EmotionProfile *> emotions_profile){
		//Gets the description of the emotion
		EmotionProfile * temp_emotion_description = emotions_profile[emotion_and_action];
		//For each emotion change the parameters
		for(list<SimpleActionExecution *>::iterator it = list_simple_action->begin();
				it != list_simple_action->end(); it++){
			if((*it)->getSimpleActionType()==TypeActionTrajectory){
				SimpleActionTrajectoryExecution * temp_trajectory_execution
				= dynamic_cast<SimpleActionTrajectoryExecution *> (*it);
				if(typeid(temp_trajectory_execution->getParameterTranslation()).name()==typeid(ParameterVelocity).name()){
					this->modifyUsingVelocity(*it,temp_emotion_description);
				}else if(typeid(temp_trajectory_execution->getParameterTranslation()).name()==typeid(ParameterTime).name()){
					this->modifyUsingTime(*it,temp_emotion_description);
				}else if(typeid(temp_trajectory_execution->getParameterTranslation()).name()==typeid(ParameterAcceleration).name()){
					this->modifyUsingAcceleration(*it,temp_emotion_description);
				}else{
					this->modifyUsingPreDefinedValues(*it,temp_emotion_description);
				}
			}
		}
}

void ActionModification::modifyUsingPreDefinedValues(SimpleActionExecution * action_execution,EmotionProfile * emotion_profile){

}

void ActionModification::modifyUsingVelocity(SimpleActionExecution * action_execution,EmotionProfile * emotion_profile){

}

void ActionModification::modifyUsingTime(SimpleActionExecution * action_execution,EmotionProfile * emotion_profile){

}

void ActionModification::modifyUsingAcceleration(SimpleActionExecution * action_execution,EmotionProfile * emotion_profile){

}
