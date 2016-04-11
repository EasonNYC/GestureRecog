#ifndef ACCELEROMETERS_H
#define ACCELEROMETERS_H

// initialize accelerometers on STM32F4 Discovery Board
int init_accelerometers();

// get readings from X, Y, Z axes in units of g (acceleration due to gravity; 1 g = 9.81 m/s^2)
void read_accelerometers(float *b);

#endif
