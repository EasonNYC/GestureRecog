/*
 * timed_task.h
 *
 *  Created on: Apr 3, 2016
 *      Author: eason
 */

#ifndef TIMED_TASK_H_
#define TIMED_TASK_H_
#include <stdio.h>
extern volatile uint32_t msTicks;

//func pointer  to a task function. Task must have no args and return void
typedef void (*funcptr)(void);

/**
  * @fn void add_timed_task(funcptr myfunc,float interval_sec)
  * @brief Adds a timed task to the task array
  * @param myfunc
  * @param interval_sec
  */
void add_timed_task(funcptr myfunc,float interval_sec);

//calls task functions when ready in your main loop
void execute_tasks(void);

//prints number of times each task is called
void printtimes(void);

#endif /* TIMED_TASK_H_ */
