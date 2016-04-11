/*
 * accavg.h
 *
 *  Created on: Apr 3, 2016
 *      Author: eason
 */

#ifndef ACCELEROMETERS_ACCAVG_H_
#define ACCELEROMETERS_ACCAVG_H_
#include "math.h"

//circular array which holds raw accel data
#define NUMSAMPLES 5

void calc_average(float* avg_x, float* avg_y, float* avg_z);
void calc_pitch_roll(float acc_x, float acc_y, float acc_z, float *pitch, float *roll);
void printPitchRoll(void);

#endif /* ACCELEROMETERS_ACCAVG_H_ */
