/*
 * OscillateShoulderDescription.h
 *
 *  Created on: May 5, 2014
 *      Author: julian
 */

#ifndef OSCILLATESHOULDERDESCRIPTION_H_
#define OSCILLATESHOULDERDESCRIPTION_H_

#include "../SimpleActionDescription.h"
#include "../../../general_execution/action_execution/OscillateShoulderExecution.h"

class OscillateShoulderDescription: public SimpleActionDescription {
public:
	OscillateShoulderDescription();
	virtual ~OscillateShoulderDescription();
	list<SimpleActionExecution *> Analyze(void);
	void setParameterPointPosition(PointPositionParameter * parameter_destination);
	PointPositionParameter * getParameterPosition();
	void setParameterTranslation(ParameterTranslation * parameter_translation);
	ParameterTranslation * getParameterTranslation();

private:
	/**
	 * This parameter specifies the final destination of the robot.
	 * Therefore, it is used the abstract class ParameterPosition,
	 */
	PointPositionParameter *parameter_destination;
	/**
	 * This parameter constrains the trajectory: time, velocity, acceleration.
	 * This parameter could be optional
	 */
	ParameterTranslation *parameter_translation;
};

#endif /* OSCILLATESHOULDERDESCRIPTION_H_ */
