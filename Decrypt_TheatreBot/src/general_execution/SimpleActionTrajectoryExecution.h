/*
 * SimpleActionTrajectoryExecution.h
 *
 *  Created on: May 9, 2014
 *      Author: julian
 */

#ifndef SIMPLEACTIONTRAJECTORYEXECUTION_H_
#define SIMPLEACTIONTRAJECTORYEXECUTION_H_

#include "SimpleActionExecution.h"
#include "../general_description/parameters_description/parameters_instances/ParameterTranslation.h"

class SimpleActionTrajectoryExecution: public SimpleActionExecution {
public:
	SimpleActionTrajectoryExecution();
	virtual ~SimpleActionTrajectoryExecution();
	void setParameterTranslation(ParameterTranslation *parameter_translation);
	ParameterTranslation* getParameterTranslation();

protected:
	/**
	 * This parameter constrains the trajectory: time, velocity, acceleration.
	 * This parameter could be optional
	 */
	ParameterTranslation *parameter_translation;

};

#endif /* SIMPLEACTIONTRAJECTORYEXECUTION_H_ */
