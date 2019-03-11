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
  
  Serial.printf("ESP32 Chip ID = %04X", (uint16_t)(get_chip_id() >> 32)); //print High 2 bytes
  Serial.printf("%08X\n", (uint32_t)get_chip_id()); //print Low 4bytes.
}

void loop() {
  static int i = 0;
  while (1) {
    display.clear();
    oled_progress(i);
    oled_progress2(100-i);
    oled_progress3(i/2);
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


