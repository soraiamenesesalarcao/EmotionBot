///////////////////////////////////////////////////////////
//  EmotionProfile.cpp
//  Implementation of the Class EmotionProfile
//  Created on:      01-abr-2014 05:53:24 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#include "EmotionProfile.h"


EmotionProfile::EmotionProfile(){

}



EmotionProfile::~EmotionProfile(){
	for(vector<ActionChanges *>::iterator it = emotion_profile_actions.begin();
			it != emotion_profile_actions.end(); it++){
		delete *it;
	}
}





string EmotionProfile::getEmotionProfileName(){

	return  this->emotion_profile_name;
}


void EmotionProfile::setEmotionProfileName(string emotion_profile_name){

	this->emotion_profile_name = emotion_profile_name;
}


string EmotionProfile::getEmotionProfileAction(){

	return  this->emotion_profile_action;
}


void EmotionProfile::setEmotionProfileAction(string emotion_profile_action){

	this->emotion_profile_action = emotion_profile_action;
}


string EmotionProfile::getEmotionProfileDescription(){

	return  this->emotion_profile_description;
}

string EmotionProfile::getEmotionProfileEmotion(){
	return this->emotion_profile_emotion;
}
void EmotionProfile::setEmotionProfileEmotion(string emotion_profile_emotion){
	this->emotion_profile_emotion = emotion_profile_emotion;
}


void EmotionProfile::setEmotionProfileDescription(string emotion_profile_description){

	this->emotion_profile_description = emotion_profile_description;
}


vector<ActionChanges *> EmotionProfile::getEmotionProfileActions(){
	return  this->emotion_profile_actions;
}


void EmotionProfile::setEmotionProfile(vector<ActionChanges *> emotion_profile_actions){

	this->emotion_profile_actions = emotion_profile_actions;
}

void EmotionProfile::addEmotionProfileActionChanges(ActionChanges* emotion_profile_action_changes){
	this->emotion_profile_actions.push_back(emotion_profile_action_changes);
}
