#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void AsycWebServer_func(void*) 
{
  VOID SETUP() 
  {                       
    server.on("/heap", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(200, "text/plain", String(ESP.getFreeHeap()));
    });
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
      char buf[50];
      sprintf(buf, "<H2>Temp  : %.2f<br>\nHumid : %.2f<br> YAW= %.2f<br> PITCH= %.2f<br> ROLL= %.2f<br></H2> \n", xDHT_temp, xDHT_humid,xax,xay,xaz);  
      request->send(200, "text/html", String(buf));
    });
    
    server.onNotFound([](AsyncWebServerRequest * request) {
      Serial.println("[AsyncWebServer] Page NOT FOUND ");
      request->send(404, "text/plain", "Page not found");
    });

    Serial.println("[AsyncWebServer] start!");
    Serial.printf ("[AsyncWebServer] Open http://%s on the browser.\n", WiFi.localIP().toString().c_str());
    server.begin();
  }

  VOID LOOP() 
  {                        
    DELAY(1);                        
  }
}