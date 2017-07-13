#include "stm32f10x.h"
#include "led.h"

/*********FreeRTOS**************/
#include "FreeRTOS.h"  
#include "task.h" 
#include "queue.h" 
#include "list.h"  
#include "portable.h"  
#include "FreeRTOSConfig.h"

void  vLED_Task( void *pvParameters ) 
{  
	for(;;) 
	{  
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);  
		vTaskDelay(1000 / portTICK_RATE_MS);   
		GPIO_SetBits(GPIOA, GPIO_Pin_8);    
		vTaskDelay(1000 / portTICK_RATE_MS);  
	}  
}

int main()
{
	LED_Init();
	
	xTaskCreate( vLED_Task, "LED", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL);
	
	vTaskStartScheduler();

	for(;;);
}
