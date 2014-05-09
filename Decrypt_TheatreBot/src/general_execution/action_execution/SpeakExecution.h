/*
 * SpeakExecution.h
 *
 *  Created on: May 1, 2014
 *      Author: julian
 */

#ifndef SPEAKEXECUTION_H_
#define SPEAKEXECUTION_H_

#include "../SimpleActionExecution.h"

class SpeakExecution: public SimpleActionExecution {
public:
	SpeakExecution();
	virtual ~SpeakExecution();
	bool executeAction(string platform);
	void setParameterPhraseToSay(string *phrase_to_say);
	string  *getParameterPhraseToSay();

private:
	string *phrase_to_say;
};

#endif /* SPEAKEXECUTION_H_ */
