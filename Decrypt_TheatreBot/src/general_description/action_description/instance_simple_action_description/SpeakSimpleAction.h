/*
 * SpeakSimpleAction.h
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#ifndef SPEAKSIMPLEACTION_H_
#define SPEAKSIMPLEACTION_H_

#include "../SimpleActionDescription.h"
#include "../../../general_execution/action_execution/SpeakExecution.h"

class SpeakSimpleAction: public SimpleActionDescription {
public:
	SpeakSimpleAction();
	virtual ~SpeakSimpleAction();
	list<SimpleActionExecution *> Analyze();
	void setParameterPhraseToSay(string *phrase_to_say);
	string  *getParameterPhraseToSay();
private:
	string * phrase_to_say;
};

#endif /* SPEAKSIMPLEACTION_H_ */
