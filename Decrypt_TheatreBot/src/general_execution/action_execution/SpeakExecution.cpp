/*
 * SpeakExecution.cpp
 *
 *  Created on: May 1, 2014
 *      Author: julian
 */

#include "SpeakExecution.h"

SpeakExecution::SpeakExecution() {
	this->phrase_to_say = NULL;
	this->action_name = "speak";
	this->type_action = TypeActionSpeak;
}

SpeakExecution::~SpeakExecution() {
	delete this->phrase_to_say;
}
bool SpeakExecution::executeAction(string platform){
	bool result = false;
	if(platform == "triskar_big"){

	}else if(platform == "triskar_small"){
		cout<<"executing speak"<<endl;
	}
	return result;
}
void SpeakExecution::setParameterPhraseToSay(string *phrase_to_say){
	this->phrase_to_say = phrase_to_say;
}
string  *SpeakExecution::getParameterPhraseToSay(){
	return this->phrase_to_say;
}

