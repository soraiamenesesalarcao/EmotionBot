/*
 * WalkCompoundAction.h
 *
 *  Created on: Apr 30, 2014
 *      Author: julian
 */

#ifndef WALKCOMPOUNDACTION_H_
#define WALKCOMPOUNDACTION_H_

#include <typeinfo>
#include "../SequenceAbstractActionDescription.h"
#include "../instance_simple_action_description/MoveBodySimpleActionDescription.h"
#include "../instance_simple_action_description/OscillateShoulderDescription.h"
#include "../../parameters_description/parameters_instances/ParameterVelocity.h"
#include "../../parameters_description/parameters_instances/ParameterTime.h"
#include "../../parameters_description/parameters_instances/ParameterAcceleration.h"

class WalkCompoundAction:  public SequenceAbstractActionDescription{
public:
	WalkCompoundAction();
	virtual ~WalkCompoundAction();
	list<SimpleActionExecution *> Analyze();
	void setParameterPosition(ParameterPosition * parameter_destination);
	ParameterPosition * getParameterPosition();
	void setParameterTrnaslation(ParameterTranslation * parameter_translation);
	ParameterTranslation * getParameterTranslation();
	float getShoulderReduceFactor();
	void setShoulderReduceFactor(float reduce_factor);
private:
	void reduceTranslationParameterShoulder();

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
	//Action which compound this action
	OscillateShoulderDescription * oscillate_shoulder_simple_action;
	MoveBodySimpleActionDescription * move_body_simple_action;
	/*
	 * This parameters reduce the velocity of the oscillation of the shoulder
	 * this is done because not all the time the desire velocity on this movement
	 * should be the same in the other one
	 */
	float reduce_factor_shoulder;

};

#endif /* WALKCOMPOUNDACTION_H_ */
