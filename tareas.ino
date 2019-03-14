volatile unsigned int gps_data_valid;

void tareas_init() {
  xTaskCreate(task_update_oled, "OLED", 10000, NULL, 0, NULL);
  xTaskCreate(task_gps, "GPS", 100000, NULL, 0, NULL);
}

void task_gps(void * pvParameters) {
  while (true) {
    gps_printdata();
  }
}

void task_update_oled(void * pvParameters) {
  unsigned int i = 0;
  static unsigned long t = 0;

  while (true) {
    if (millis() - t > 5000) {
      if (sensor_being_readed_main == 0) {
        sensor_being_readed_task=true;
        t = millis();
        wifi_connect();
        Serial.println("Wifi Enviando en TASK");
        sensor_being_readed_task=false;
      }
      else{
        Serial.println("Wifi Bloqueado por MAIN");
      }
    }
  }
}

