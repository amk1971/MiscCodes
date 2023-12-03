#include <stdint.h>
#include "system.h"
#include "bme280.h"                  

/*Sample Application Information:

The humidity and temperature values are contained in a 
variable of type 'bme280_t' whose address is passed as an 
argument to the 'BME280_Get_Data()' function.

For demonstration purposes, the structure variable that contains
the sensor data is named 'bme280Data' and declared as follows:

	bme280_t bme280Data;

To check the humidity and temperature readings of the sensor,
1.) set a breakpoint on the line in which the 'System_Timer_DelayMs()
function' is called in the 'while(1) loop'.
2.) run the keil debugger
3.) when the debugger stops, check the 'bme280Data' humidity and
temperature structure members for the BME280 sensor's readings.
*/

int main(void)
{
	//Local variables
	bme280_t bme280Data;
	//Initializations
	System_Init();
	BME280_Init();
	HAL_Init();  // Initialize the HAL Library
	
	while(1)
	{
		//Take measurements every 500ms
		BME280_GetData(&bme280Data);
		HAL_Delay(500);
	}
	
}
