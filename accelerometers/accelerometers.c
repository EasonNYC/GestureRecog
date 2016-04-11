#include "accelerometers.h"
#include "tm_accelerometers/tm_stm32f4_lis302dl_lis3dsh.h"

// initialize accelerometers on STM32F4 Discovery Board
int init_accelerometers()
{
	TM_LIS302DL_LIS3DSH_Init(TM_LIS3DSH_Sensitivity_2G, TM_LIS3DSH_Filter_50Hz);
  return 0;
}

// get readings from X, Y, Z axes in units of g (acceleration due to gravity; 1 g = 9.81 m/s^2)
void read_accelerometers(float *b)
{
	TM_LIS302DL_LIS3DSH_t Axes_Data;
	TM_LIS302DL_LIS3DSH_ReadAxes(&Axes_Data);
	b[0] = ((float)(Axes_Data.X))/1000.0;
	b[1] = ((float)(Axes_Data.Y))/1000.0;
	b[2] = ((float)(Axes_Data.Z))/1000.0;
}

