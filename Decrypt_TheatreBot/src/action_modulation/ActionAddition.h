/*
 * ActionAddition.h
 *
 *  Created on: May 2, 2014
 *      Author: julian
 */

#ifndef ACTIONADDITION_H_
#define ACTIONADDITION_H_

#include <list>
#include <string>
#include <vector>
#include <map>
#include "../general_execution/SimpleActionTrajectoryExecution.h"
#include "../general_description/emotion_description/EmotionProfile.h"
#include "../general_description/action_description/instance_simple_action_description/MoveBodySimpleActionDescription.h"
#include "../general_description/action_description/instance_simple_action_description/MoveShoulderSimpleActionDescription.h"
#include "../general_description/action_description/instance_simple_action_description/SpeakSimpleAction.h"
#include "../general_description/action_description/instance_simple_action_description/OscillateBodyActionDescription.h"
#include "../general_description/action_description/instance_simple_action_description/OscillateShoulderDescription.h"

using std::string;
using std::list;
using std::map;
using std::vector;

class ActionAddition {
public:
	ActionAddition();
	virtual ~ActionAddition();
	void addAdditionalSimpleActions(string emotion_and_action, list<SimpleActionExecution *> *list_simple_action ,
			map<string,EmotionProfile *> emotions_profile);
private:
	list<string> searchMissingActions(vector<ActionChanges *> action_changes, list<SimpleActionExecution *> list_simple_action);
	bool isTheAction(string action_name, list<SimpleActionExecution *> list_simple_action);
	void instanceMissingActions(list<string> list_missing_actions,list<SimpleActionExecution *> *list_simple_action);
	SimpleActionExecution * instanceMissingAction(string missing_action_name);
};

#endif /* ACTIONADDITION_H_ */
