///////////////////////////////////////////////////////////
//  AbstractAction.h
//  Implementation of the Class AbstractAction
//  Created on:      01-abr-2014 05:53:23 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#ifndef ABSTRACTACTIONDESCRIPTION_H
#define ABSTRACTACTIONDESCRIPTION_H

#include <vector>
#include <list>
#include <cstdlib>
#include "../parameters_description/ParameterValue.h"
#include "../../general_execution/SimpleActionExecution.h"

using std::vector;
using std::list;

/*
 * Actions are generated using the composed pattern. Thus, this class is abstract to be
 * used by other classes to generate composed generation of actions.
 */
class AbstractActionDescription
{

public:
	AbstractActionDescription();
	virtual ~AbstractActionDescription();

	virtual list<SimpleActionExecution *> Analyze(void)=0;
	string getActionDescription();
	string getActionName();
	list<string> getRobotPartsUsed();
	void setRobotPartsUsed(list<string> robot_parts_used);
	void addRobotPartUsed(string part_used);
	void setActionDescription(string description);
	void setActionName(string action_name);
	vector<ParameterValue *> getActionParameters();
	void setActionParameter(vector<ParameterValue *> action_parameters);
	void addActionParameter(ParameterValue * action_parameter);

protected:
	string action_description;
	string action_name;
	list<string> robot_parts_used;
	vector<ParameterValue *> action_parameters;

};
#endif // !defined(ABSTRACT_ACTION)
