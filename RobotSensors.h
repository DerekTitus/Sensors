/*
 * RobotSensors.h
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Derek.Titus
 */

#ifndef ROBOTSENSORS_H_
#define ROBOTSENSORS_H_

#include <msp430.h>


void initSensors();
unsigned int initRightSensor();
unsigned int initLeftSensor();
unsigned int initCenterSensor();
unsigned int LeftWall();

#endif /* ROBOTSENSORS_H_ */
