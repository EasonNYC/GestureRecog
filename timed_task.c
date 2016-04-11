#include "timed_task.h"
#define MAXNUMTASKS 25

 typedef struct _TimedTask {
 funcptr task;
 uint32_t msinterval;
 uint32_t last_called;
 uint32_t numcalls;
 } TimedTask;

 //main tasks array
 TimedTask timed_tasks[MAXNUMTASKS];

  /**
  * @fn void add_timed_task(funcptr myfunc,float interval_sec)
  * @brief Adds a timed task to the task array
  * @param myfunc
  * @param interval_sec
  */

 void add_timed_task(funcptr myfunc,float interval_sec){

     for(size_t i =0; i < MAXNUMTASKS;++i){

         if(timed_tasks[i].task == NULL){
                 printf("Adding task %i [%f seconds]\n",i,interval_sec);
             timed_tasks[i].task = myfunc;
             timed_tasks[i].msinterval = (long)(interval_sec*1000.0);
             timed_tasks[i].last_called = 0;
             timed_tasks[i].numcalls = 0;
             return;
         }
     }
}

 //(PUBLIC) function which executes all timed tasks (to be called in a while loop)
  void execute_tasks(void)
 {
     for(size_t i = 0; i < MAXNUMTASKS; ++i)
     {

         if(timed_tasks[i].task != NULL)
         {
             if (msTicks >= (timed_tasks[i].last_called + timed_tasks[i].msinterval))
             {
             	//save last called, count number of calls so far, and execute task
 	            timed_tasks[i].last_called = msTicks;
 	            timed_tasks[i].numcalls++;
 	            timed_tasks[i].task();
 	         }
 	     }
    }
  }

  // (PUBLIC) print the number oftimes a task is called
  void printtimes(void)
  {
	  printf("\nnum calls\n");
      for(int i = 0; i < MAXNUMTASKS;++i)
      {
          if(timed_tasks[i].task != NULL){
          printf("t%i=%i\n",i,timed_tasks[i].numcalls);
          }
      }
      printf("\n");
  }
  /*
   float get_time()
   {
   return .001*msTicks;
   }


  //task related
    add_timed_task(update,.020); //seconds
    add_timed_task(printPitchRoll,1.0);
    add_timed_task(collectAccelData,.010);

      while (1)
    {
  	//execute all tasks
     execute_tasks();
    }
*/
