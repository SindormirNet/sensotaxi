#include "SSD1306.h"
#define PULSADOR 0
#define LED_BUILTIN 2

extern SSD1306 display;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(112500);
  Serial.println("Iniciando SensorTaxi");

  oled_init();
  oled_intro();

  neopixel_setup();

  neopixel_all_on();

  wifi_setup();
  bme280_setup();
  gps_setup();

  sound_setup();
  mq135_setup();
  mq132_setup();

  luz_setup();
  tareas_init();
  neopixel_all_off();


  Serial.printf("ESP32 Chip ID = %04X", (uint16_t)(get_chip_id() >> 32)); //print High 2 bytes
  Serial.printf("%08X\n", (uint32_t)get_chip_id()); //print Low 4bytes.
}

void loop() {
  static int i = 0;
  while (1) {
    display.clear();

    //Sensores reales
    oled_temp(bme280_get_temp());
    oled_pres(bme280_get_pres());
    oled_luz(luz_get_value());
    oled_mq135(mq135_get_value());
    oled_mq132(mq132_get_value());
    oled_sound(sound_get_value());


    display.display();
    delay(10);

    if (i++ == 100) i = 0;

  }
}


