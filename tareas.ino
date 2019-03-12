void tareas_init() {
  xTaskCreate(task_led_blink, "parpadeo", 10000, NULL, 0, NULL);
  xTaskCreate(task_update_oled, "OLED", 10000, NULL, 0, NULL);
  xTaskCreate(task_gps, "GPS", 10000, NULL, 0, NULL);
}

void task_led_blink(void * pvParameters) {
  while (true) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
  }
}

void task_gps(void * pvParameters) {
  while (true) {
    gps_printdata2();
  }
}



void task_update_oled(void * pvParameters) {
  unsigned int i = 0;
  static unsigned long t = 0;
 
  while (true) {
    if (millis() - t > 5000) {
      t = millis();
      unsigned long tiempo_ini = millis();
      wifi_connect();
      Serial.print("Tiempo que ha pasado: ");
      Serial.println(millis() - tiempo_ini);
    }
  }
}

