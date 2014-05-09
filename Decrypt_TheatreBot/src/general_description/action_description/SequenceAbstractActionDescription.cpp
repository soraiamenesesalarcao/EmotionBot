///////////////////////////////////////////////////////////
//  SequenceAbstractAction.cpp
//  Implementation of the Class SequenceAbstractAction
//  Created on:      01-abr-2014 05:53:26 p.m.
//  Original author: Julian
///////////////////////////////////////////////////////////

#include "SequenceAbstractActionDescription.h"


SequenceAbstractActionDescription::SequenceAbstractActionDescription(){

}



SequenceAbstractActionDescription::~SequenceAbstractActionDescription(){
	//delete abstract_actions
	for(vector<AbstractActionDescription *>::iterator it = abstract_actions.begin();
			it != abstract_actions.end(); it++){
		delete *it;
	}
}

list<SimpleActionExecution *> SequenceAbstractActionDescription::Analyze(void){

	list<SimpleActionExecution *> temp;
	/*for(vector<AbstractAction>::iterator it = this->abstract_actions.begin();
			it != this->abstract_actions.end(); it++){

	}*/
	return temp;
}

vector<AbstractActionDescription *> SequenceAbstractActionDescription::getSequenceAbstractAction(){

	return this->abstract_actions;
}

void SequenceAbstractActionDescription::setSequenceAbstractAction(vector<AbstractActionDescription *> abstract_actions){
	this->abstract_actions = abstract_actions;
}

void SequenceAbstractActionDescription::addNewAbstractAction(AbstractActionDescription* abstract_action){
	this->abstract_actions.push_back(abstract_action);
}
