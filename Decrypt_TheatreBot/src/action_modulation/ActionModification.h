/*
 * ActionModification.h
 *
 *  Created on: May 2, 2014
 *      Author: julian
 */

#ifndef ACTIONMODIFICATION_H_
#define ACTIONMODIFICATION_H_

#include <list>
#include <string>
#include <map>
#include <typeinfo>
#include "../general_execution/SimpleActionTrajectoryExecution.h"
#include "../general_description/emotion_description/EmotionProfile.h"
#include "../general_description/parameters_description/parameters_instances/ParameterVelocity.h"
#include "../general_description/parameters_description/parameters_instances/ParameterTime.h"
#include "../general_description/parameters_description/parameters_instances/ParameterAcceleration.h"

using std::string;
using std::list;
using std::map;

class ActionModification {
public:
	ActionModification();
	virtual ~ActionModification();
	void modifySimpleActions(string emotion_and_action, list<SimpleActionExecution *> *list_simple_action ,
			map<string,EmotionProfile *> emotions_profile);
private:
	/*
	 * Here should be a different method for each kind of trajectory modification.
	 * If the method is not implemented the desired modification could not be done.
	 * In case that there is not any desire parameter, it would be used a pre-define values
	 */
	void modifyUsingPreDefinedValues(SimpleActionExecution * action_execution,EmotionProfile * emotion_profile);
	void modifyUsingVelocity(SimpleActionExecution * action_execution, EmotionProfile * emotion_profile);
	void modifyUsingTime(SimpleActionExecution * action_execution, EmotionProfile * emotion_profile);
	void modifyUsingAcceleration(SimpleActionExecution * action_execution, EmotionProfile * emotion_profile);
};

#endif /* ACTIONMODIFICATION_H_ */
