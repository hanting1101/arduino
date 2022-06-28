#include <TridentTD_EasyFreeRTOS32.h>

TridentOS   DHT_task, Blink_task, WiFi_task, AsyncWebServer_task, IMU_task;
void DHT_func(void*), Blink_func(void*), WiFi_func(void*), AsyncWebServer_func(void*), MPU_func(void*);


int     xBlink_Delay;   
float   xDHT_temp;       
float   xDHT_humid;      
float   xax,xay,xaz;

void setup()
{  
  Serial.begin(115200); Serial.println();
    
  DHT_task.start( DHT_func );
  WiFi_task.start( WiFi_func );  
  IMU_task.start(MPU_func );
  
}

void loop(){}  