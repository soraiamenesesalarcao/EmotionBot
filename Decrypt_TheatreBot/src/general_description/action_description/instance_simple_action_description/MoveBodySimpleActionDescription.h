/*
 * MoveSimpleActionDescription.h
 *
 *  Created on: Apr 16, 2014
 *      Author: julian
 */

#ifndef MOVESIMPLEACTIONDESCRIPTION_H_
#define MOVESIMPLEACTIONDESCRIPTION_H_

#include "../SimpleActionDescription.h"
#include "../../../general_execution/action_execution/MoveBodyExecution.h"

class MoveBodySimpleActionDescription: public SimpleActionDescription {
public:
	MoveBodySimpleActionDescription();
	virtual ~MoveBodySimpleActionDescription();
	list<SimpleActionExecution *> Analyze(void);
	void setParameterPosition(ParameterPosition * parameter_destination);
	ParameterPosition * getParameterPosition();
	void setParameterTrnaslation(ParameterTranslation * parameter_translation);
	ParameterTranslation * getParameterTranslation();

private:
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
};

#endif /* MOVESIMPLEACTIONDESCRIPTION_H_ */
