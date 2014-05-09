/*
 * ActionTest1.h
 *
 *  Created on: Apr 3, 2014
 *      Author: julian
 */

#ifndef ACTIONTEST1_H_
#define ACTIONTEST1_H_


#include "../../general_description/action_description/SequenceAbstractActionDescription.h"
//#include "../../general_description/action_description/intance_action_description/MoveBodySimpleActionDescription.h"
//#include "../../general_description/action_description/intance_action_description/MoveShoulderSimpleActionDescription.h"
/*
 * This class is used to test the systems. Instead of reading a file, all the actions are
 * code created.
 */
class ActionTest1 {
public:
	ActionTest1();
	virtual ~ActionTest1();
	SequenceAbstractActionDescription* getWalDescription();
	SequenceAbstractActionDescription* getWalkAndTalkDescription();

private:
	void generateWalkDescription();
	void generateWalkAndTalkDescription();
	/**
	 * Walk
	 * this actions is composed by move (simple action) and oscillateShoulders (simple action)
	 */
	SequenceAbstractActionDescription *walk_description;
	/*
	 * These parameters are instance when the new action is ask to be perform
	 */
	ActionParameter *parameter_position;
	ActionParameter *parameter_translation;
	/**
	 * Walk and talk
	 * this action is composed by walk (abstract action) and talk (simple action)
	 */
	SequenceAbstractActionDescription *walk_and_talk_description;
};

#endif /* ACTIONTEST1_H_ */
