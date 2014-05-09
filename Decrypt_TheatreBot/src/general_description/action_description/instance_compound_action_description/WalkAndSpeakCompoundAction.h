/*
 * WalkAndSpeakCompoundAction.h
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#ifndef WALKANDSPEAKCOMPOUNDACTION_H_
#define WALKANDSPEAKCOMPOUNDACTION_H_

#include "../SequenceAbstractActionDescription.h"
#include "WalkCompoundAction.h"
#include "../instance_simple_action_description/SpeakSimpleAction.h"

class WalkAndSpeakCompoundAction:  public SequenceAbstractActionDescription {
public:
	WalkAndSpeakCompoundAction();
	virtual ~WalkAndSpeakCompoundAction();
	list<SimpleActionExecution *> Analyze();
	void setParameterPosition(ParameterPosition * parameter_destination);
	ParameterPosition * getParameterPosition();
	void setParameterTrnaslation(ParameterTranslation * parameter_translation);
	ParameterTranslation * getParameterTranslation();
	void setParameterPhraseToSay(string *phrase_to_say);
	string *getParameterPhraseToSay();
private:
	WalkCompoundAction *walk_action;
	SpeakSimpleAction *speak_simple_action;
	string * phrase_to_say;
	/**
	 * This parameter specifies the final destination of the robot.
	 * Therefore, it is used the abstract class ParameterPosition,
	 */
	ParameterPosition *parameter_destination;
	/**
	 * This parameter constrains the trajectory: time, velocity, acceleration.
	 * This parameter could be optional
	 */
	ParameterTranslation *parameter_translation;
};

#endif /* WALKANDSPEAKCOMPOUNDACTION_H_ */
