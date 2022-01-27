/*2. Create 3 realtime tasks each with the periodcity T1=1000ms, T2=2000ms, T3=5000ms. Also create use oneshot software timer to trigger a callback function from T3 after 10000ms.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t motor_timer_handle;

void Task1(void *pvParameters)
{
while(1)
{
    printf("Task1 \n");
    vTaskDelay(1000/portTICK_PERIOD_MS);
}

}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
    vTaskDelay(2000/portTICK_PERIOD_MS);
}

}

void Task3(void *pvParameters)
{
while(1)
{
    printf("Task3 \n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    motor_timer_handle= xTimerCreate("MotorOFF",pdMS_TO_TICKS(10000),pdFALSE,NULL,TurnMotorOFF); //create timer
    xTimerStart(motor_timer_handle,0);
}
}

void TurnMotorOFF(TimerHandle_t xTimer) //callback
{
printf("Turning motor off\n");
}

void  app_main()
{
    printf("Hello Free RTOS\n");
    
    
    xTaskCreate(Task1,"Task1",2048,NULL,5,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,6,NULL);
    xTaskCreate(Task3,"Task3",2048,NULL,7,NULL);
    
}
