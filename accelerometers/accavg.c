/*
 * accavg.c
 *
 *  Created on: Apr 3, 2016
 *      Author: eason
 */
#include "accavg.h"


//struct which holds a raw sample of accel xyz data
typedef struct _acceldata {
	float x;
	float y;
	float z;
} acceldata;

//circular array which hold all of our samples for averaging
acceldata accel_data_window[NUMSAMPLES];

//calculates average from last 5 readings of accel xyz
void calc_average(float* avg_x, float* avg_y, float* avg_z)
{
	float x =0;
	float y =0;
	float z =0;

	for(int i =0;i<NUMSAMPLES;++i)
	{
		//sum most recent samples
		x+= accel_data_window[i].x;
		y+= accel_data_window[i].y;
		z+= accel_data_window[i].z;
	}

	//return average xyz data in supplied pointer arguments
	*avg_x = x/NUMSAMPLES;
	*avg_y = y/NUMSAMPLES;
	*avg_z = z/NUMSAMPLES;
}

//collects raw accel data and stores it in an array for later averaging
void collectAccelData(void)
{
	static long nw = 0; //circular index

	//get new accel xyz data
	float a[3];
	read_accelerometers(a);

	//store it in circular array
	accel_data_window[nw].x = a[0];
	accel_data_window[nw].y = a[1];
	accel_data_window[nw].z = a[2];

	//increment circular array before leaving
	nw++;
	if(nw > NUMSAMPLES) nw = 0;

}

//calc pitch and roll from given xyz data
void calc_pitch_roll(float acc_x, float acc_y, float acc_z, float *pitch, float *roll)
{
	*roll = (180.0/M_PI)*atan2(acc_y, acc_z);
	*pitch = (180.0/M_PI)*atan2(-acc_x, sqrt(acc_y*acc_y+acc_z*acc_z));
}

//returns average pitch and roll of last 5 raw samples
void getPitchRoll(float* p, float* r){

	//avg xyz readings
	float x,y,z;
   calc_average(&x, &y, &z);

	//calculate pitch and roll
	calc_pitch_roll(x, y, z, p, r);

}

//print pitch and roll
void printPitchRoll(void){

	float p = 0.0;
	float r = 0.0;
	getPitchRoll(&p,&r);

   printf("Pitch = %f, Roll = %f\n", p, r);
}
