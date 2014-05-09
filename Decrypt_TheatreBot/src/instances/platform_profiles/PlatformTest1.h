/*
 * PlatformTest1.h
 *
 *  Created on: May 2, 2014
 *      Author: julian
 */

#ifndef PLATFORMTEST1_H_
#define PLATFORMTEST1_H_

#include <map>
#include "../../general_description/platform_description/PlatformDescription.h"

using std::map;

class PlatformTest1 {
public:
	PlatformTest1();
	virtual ~PlatformTest1();
	map<string, PlatformDescription *> getPlatformDescription();
private:
	map<string, PlatformDescription *> platforms_description;
};

#endif /* PLATFORMTEST1_H_ */
