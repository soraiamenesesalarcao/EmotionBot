/*
 * OscillateShoulderExecution.h
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#ifndef OSCILLATESHOULDEREXECUTION_H_
#define OSCILLATESHOULDEREXECUTION_H_

#include "../SimpleActionTrajectoryExecution.h"
#include "../../general_description/parameters_description/parameters_instances/PointPositionParameter.h"

class OscillateShoulderExecution: public SimpleActionTrajectoryExecution {
public:
	OscillateShoulderExecution();
	virtual ~OscillateShoulderExecution();
	bool executeAction(string platform);
	void setParameterDestination(PointPositionParameter *parameter_destination);
	PointPositionParameter* getParameterDestination();

private:
	/**
	 * This parameter specifies the final destination of the robot.
	 * Therefore, it is used the abstract class ParameterPosition,
	 */
	PointPositionParameter *parameter_destination;
};

#endif /* OSCILLATESHOULDEREXECUTION_H_ */
