void Blink_func(void* arg){  
  VOID SETUP(){                       
    pinMode(BLINK_LED_PIN,OUTPUT);
    if( xBlink_Delay <= 0) xBlink_Delay = DEFAULT_BLINK_DELAY;
  }

  VOID LOOP() {                       
    digitalWrite(BLINK_LED_PIN,HIGH);
    DELAY(xBlink_Delay);              
    digitalWrite(BLINK_LED_PIN,LOW);
    DELAY(xBlink_Delay);
  }
}