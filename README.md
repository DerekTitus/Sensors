Sensors
=======
This file contains the code to initialize the sensors on the robot.

Functions
==
void initSensors()

initializes the sensors

unsigned int initRightSensor()

unsigned int initLeftSensors()

unsigned int initCenterSensor()

initializes all of the sensors

unsigned int LeftWall()

Not needed in this portion of the lab

Example code:
==
#include <msp430.h> 
#include "RobotSensors.h"
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    P1DIR |= BIT0|BIT6;
    P1OUT &= ~(BIT0|BIT6);

    initSensors();

    while(1)
    {
    	initLeftSensor();
    	if (initLeftSensor() >= 0x230){
    		P1OUT |= BIT0;}
    	else{
    		P1OUT &= ~BIT0;}

    	initRightSensor();
    	if (initRightSensor() >= 0x270){
    		P1OUT |= BIT6;
    	}
    	else{
    		P1OUT &= ~BIT6;
    	}
    	}


}
