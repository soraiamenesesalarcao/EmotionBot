/*
 * EmotionTest1.h
 *
 *  Created on: Apr 15, 2014
 *      Author: julian
 */

#ifndef EMOTIONTEST1_H_
#define EMOTIONTEST1_H_

#include "../../general_description/emotion_description/EmotionProfile.h"

class EmotionTest1 {
public:
	EmotionTest1();
	virtual ~EmotionTest1();

	void createMoveHappy();
	void createMoveSad();
	void createMoveAngry();

	EmotionProfile * getEmotionProfileMoveHappy();
	EmotionProfile * getEmotionProfileMoveAngry();
	EmotionProfile * getEmotionProfileMoveSad();
	EmotionProfile * getEmotionProfileMoveFear();
	EmotionProfile * getEmotionProfileMoveCuriosity();
	EmotionProfile * getEmotionProfileMoveEmbarrassment();
	EmotionProfile * getEmotionProfileMoveDisgust();


private:
	//Happy
	EmotionProfile *emotion_profile_happy_move;
	EmotionProfile *emotion_profile_happy_oscillate_shoulder;
	//Angry
	EmotionProfile *emotion_profile_angry_move;
	EmotionProfile *emotion_profile_angry_oscillate_shoulder;
	//Sad
	EmotionProfile *emotion_profile_sad_move;
	EmotionProfile *emotion_profile_sad_oscillate_shoulder;
	//Fear
	EmotionProfile *emotion_profile_fear_move;
	EmotionProfile *emotion_profile_fear_oscillate_shoulder;
	//Curiosity
	EmotionProfile *emotion_profile_curiosity_move;
	EmotionProfile *emotion_profile_curiosity_oscillate_shoulder;
	//Embarrassment
	EmotionProfile *emotion_profile_embarrassment_move;
	EmotionProfile *emotion_profile_embarrassment_oscillate_shoulder;
	//Disgust
	EmotionProfile *emotion_profile_disgust_move;
	EmotionProfile *emotion_profile_disgust_oscillate_shoulder;

};

#endif /* EMOTIONTEST1_H_ */
