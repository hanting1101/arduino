#include <DHT.h>

#define DHT_PIN             23           
#define DHT_TYPE            DHT11       
#define DHT_INTERVAL        1000        

void DHT_func(void*) {
  
  DHT dht(DHT_PIN, DHT_TYPE);
  
  VOID SETUP() {                      
    Serial.println("[DHT] task begin");
    dht.begin();
  }

  VOID LOOP() {                       
    float t = NAN; float h = NAN;  
    while( isnan(t) || isnan(h) ) {
      t = dht.readTemperature();
      h = dht.readHumidity();
    }
    xDHT_temp = t;  xDHT_humid = h;  
    Serial.printf("[DHT] temp : %.2f C\thumid : %.2f %%\n", xDHT_temp, xDHT_humid);
    
    DELAY(DHT_INTERVAL);              
  }
}