/*
 * SpeakSimpleAction.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#include "SpeakSimpleAction.h"

SpeakSimpleAction::SpeakSimpleAction() {
	this->phrase_to_say = NULL;
	this->robot_parts_used.push_back("speaker");
}

SpeakSimpleAction::~SpeakSimpleAction() {
	// TODO Auto-generated destructor stub
}
list<SimpleActionExecution *> SpeakSimpleAction::Analyze(){
	list<SimpleActionExecution *> temp;
	SpeakExecution *speak_execution = new SpeakExecution;
	speak_execution->setParameterPhraseToSay(this->phrase_to_say);
	temp.push_back(speak_execution);
	return temp;
}
void SpeakSimpleAction::setParameterPhraseToSay(string *phrase_to_say){
	this->phrase_to_say = phrase_to_say;
}
string  *SpeakSimpleAction::getParameterPhraseToSay(){
	return this->phrase_to_say;
}

