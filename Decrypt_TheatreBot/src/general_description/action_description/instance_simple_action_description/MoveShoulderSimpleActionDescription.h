/*
 * MoveShoulderSimpleActionDescription.h
 *
 *  Created on: Apr 17, 2014
 *      Author: julian
 */

#ifndef MOVESHOULDERSIMPLEACTIONDESCRIPTION_H_
#define MOVESHOULDERSIMPLEACTIONDESCRIPTION_H_

#include "../SimpleActionDescription.h"
#include "../../../general_execution/action_execution/MoveShoulderExecution.h"

class MoveShoulderSimpleActionDescription: public SimpleActionDescription {
public:
	MoveShoulderSimpleActionDescription();
	virtual ~MoveShoulderSimpleActionDescription();
	list<SimpleActionExecution *> Analyze();
	void setParameterPointPosition(PointPositionParameter * parameter_position);
	PointPositionParameter * getParameterPosition();
	void setParameterTranslation(ParameterTranslation  * parameter_translation);
	ParameterTranslation  * getParameterTranslation();
private:
	//Pose???
	PointPositionParameter * parameter_position;
	/**
	 * This parameter constrains the trajectory: time, velocity, acceleration.
	 * This parameter could be optional
	 */
	ParameterTranslation *parameter_translation;
};

#endif /* MOVESHOULDERSIMPLEACTIONDESCRIPTION_H_ */
