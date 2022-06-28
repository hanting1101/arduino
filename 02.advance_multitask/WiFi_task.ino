#include <WiFi.h>

#define WIFI_SSID           "bbbbbbb"
#define WIFI_PASSWORD       "kkkkkkkk"
#define WIFI_INTERVAL       2         

void WiFi_func(void*){  
 
  VOID SETUP(){                       
    WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
  }
  VOID LOOP(){                        
    if( !WiFi.isConnected() ) {
      xBlink_Delay = 80;  //ms
      Blink_task.start( Blink_func );
  
      while(!WiFi.isConnected() ) DELAY(400);
      Serial.print("[WiFi] WiFi Connected, IP : ");
      Serial.println(WiFi.localIP());
      
      Blink_task.stop();  
      AsyncWebServer_task.start(AsycWebServer_func);
    }
    
    DELAY( WIFI_INTERVAL *60000); 
  }
}