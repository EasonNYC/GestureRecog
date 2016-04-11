/*
 * gesture_recog.c
 *
 *  Created on: Apr 3, 2016
 *      Author: eason
 */
#include "gesture_recog.h"

//gesture detection states
typedef enum
{
STATE1, //0 degree pitch
STATE2, //45 degree pitch
STATE3, //0 degree pitch
NUMSTATES
} Statetype;

typedef Statetype (*stateptr)(float* ,float* );

//returns true if roll and pitch are close to some target angle (in degrees).
uint8_t isGesture(float target_r, float target_p, float* roll, float* pitch )
{
   float eps = 10.0; //+-degrees. (acceptable range of error)

   if( (fabs(target_r - *roll) <= eps) && (fabs(target_p - *pitch) <= eps) )
       return 1;
   else
       return 0;
}

//State1: detect a flat gesture
Statetype update_state1(float* roll, float* pitch)
{
static int gest1 = 0;

    if(isGesture(0.0,0.0,roll,pitch))
        gest1++;

    if(gest1 >= 50)
    {
	gest1 = 0;
	printf("going to s2\n");
        return STATE2;
    }
    else
    {

        return STATE1;
    }
}

//State2: detect a 45 degree gesture
Statetype update_state2(float* roll, float* pitch)
{
static int gest2 = 0;

    if(isGesture(45.0,0.0,roll,pitch))
         gest2++;

    if(gest2 >= 50)
    {
	 gest2 = 0;
	 printf("going to s3\n");
         return STATE3;
    }
    else
	 return STATE2;
}

//State3: detect a flat gesture
Statetype update_state3(float* roll, float* pitch)
{
static int gest3 = 0;
    if(isGesture(0.0,0.0,roll,pitch))
         gest3++;

    if(gest3 > 50)
    {
	 gest3 = 0;
    printf("gesture detected\n");
     return STATE1;
    }
    else
	 return STATE3;
}

//array which holds all state machine functions
stateptr updates[NUMSTATES] = {update_state1,update_state2,update_state3};

//update the state machine. called in main while loop.
void update(void)
{

static float p;
static float r;

getPitchRoll(&p,&r);

static Statetype state = STATE1;  //initial state at startup
state = (*updates[state])(&r,&p);
}
