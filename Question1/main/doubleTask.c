/*1. Create 3 realtime tasks each with the periodcity T1=1000ms, T2=2000ms, T3=5000ms. Also create two additional task T4 and T5 where T4 sends integer data to T5 using Messsage Queues.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t sending_queue;
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
}

}
void Task4(void *pvParameters)
{
int data =0;
   
    while(1)
    {
    printf("Task4\n");
    data ++;
    printf("data=%d\n",data);
    xQueueSend(sending_queue,&data,portMAX_DELAY );
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void Task5(void *pvParameters)
{
    int receive_data=0;
    while(1)
    {
     printf("Task5\n");
    xQueueReceive(sending_queue, &receive_data,portMAX_DELAY );
    printf("Receive =%d\n",receive_data);
    }
}
void app_main()
{
    printf("Hello FREE RTOS\n");
    sending_queue = xQueueCreate(10,sizeof(int));
    xTaskCreate(Task1,"Task1",2048,NULL,5,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,6,NULL);
    xTaskCreate(Task3,"Task3",2048,NULL,7,NULL);
    xTaskCreate(Task4,"Task4",2048,NULL,8,NULL);
    xTaskCreate(Task5,"Task5",2048,NULL,9,NULL);
}
   
 
