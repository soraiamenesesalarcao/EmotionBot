///////////////////////////////////////////////////////////
//  SequenceAbstractAction.h
//  Implementation of the Class SequenceAbstractAction
//  Created on:      01-abr-2014 05:53:26 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#ifndef SEQUENCEABTRACTACTIONDESCRIPTION_H
#define SEQUENCEABTRACTACTIONDESCRIPTION_H

#include "AbstractActionDescription.h"

class SequenceAbstractActionDescription : public AbstractActionDescription
{

public:
	SequenceAbstractActionDescription();
	virtual ~SequenceAbstractActionDescription();
	list<SimpleActionExecution *> Analyze(void);
	vector<AbstractActionDescription *> getSequenceAbstractAction();
	void setSequenceAbstractAction(vector<AbstractActionDescription *> abstract_actions);
	void addNewAbstractAction(AbstractActionDescription* abstract_action);
protected:
	vector<AbstractActionDescription *> abstract_actions;
};
#endif // !defined(EA_4AA324D9_5F99_4d3e_A878_8530959F2AC9__INCLUDED_)
