#include "SSD1306.h"
#define PULSADOR 0
#define LED_BUILTIN 2

extern SSD1306 display;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(112500);
  Serial.println("Iniciando SensorTaxi");

  //i2c_scan();
  wifi_setup();
  
  oled_init();
  luz_setup();
  tareas_init();
  oled_intro();
  get_chip_id();
}

void loop() {
  static int i = 0;
  while (1) {
    display.clear();
    oled_progress(i);
    oled_luz();
    oled_mq135(mq135_get_value());
    display.display();
    delay(1);

    if (i++ == 100) {
      i = 0;
      luz_get_value();
    }  
  }
}


