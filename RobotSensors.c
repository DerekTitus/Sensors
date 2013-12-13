/*
 * RobotSensors.c
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Derek.Titus
 */

#include "RobotSensors.h"
#define TRUE 1
#define FALSE 0
#define RightThreshold 0x200
#define LeftThreshold 0x200
#define FrontThreshold 0x200

void initSensors()
{
        ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
        ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                        // SMCLK selected
}

unsigned int initLeftSensor()
{
        ADC10CTL0 &= ~ENC; //clear the ENC bit
        ADC10CTL1 = INCH_4;  //input A4
        ADC10AE0 |= BIT4;
        ADC10CTL0 |= ENC + ADC10SC; //sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);        //LPM0, ADC10_ISR will force exit
        return ADC10MEM;
}

unsigned int initRightSensor()
{
        ADC10CTL0 &= ~ENC; //clear the ENC bit
        ADC10CTL1 = INCH_5; //input A5
        ADC10AE0 |= BIT5;
        ADC10CTL0 |= ENC + ADC10SC; //sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);
        return ADC10MEM;
}

unsigned int initCenterSensor()
{
        ADC10CTL0 &= ~ENC; //clear ENC bit
        ADC10CTL1 = INCH_3; //input A3
        ADC10AE0 |= BIT3;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);
        return ADC10MEM;
}

char RightWall()
{
        if(initRightSensor() >= RightThreshold)
        {
                return TRUE;
        }
        else
        {
                return FALSE;
        }
}

unsigned int LeftWall()
{
        if(initLeftSensor() >= LeftThreshold)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

char FrontWall()
{
        if(initCenterSensor() >= FrontThreshold)
        {
                return TRUE;
        }
        else
        {
                return FALSE;
        }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
        __bic_SR_register_on_exit(CPUOFF);
}
