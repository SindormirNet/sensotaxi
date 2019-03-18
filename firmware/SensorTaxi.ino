#include "SSD1306.h"
#define PULSADOR 0
#define LED_BUILTIN 2

int bme280_temp;
int bme280_pres;
int light;
int mq135;
int mq132;
int sound;

extern SSD1306 display;
volatile bool sensor_being_readed_main = 0;
volatile bool sensor_being_readed_task = 0;

void setup() {

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
  //accel_setup();
  tareas_init();
  neopixel_all_off();


  Serial.printf("ESP32 Chip ID = %04X", (uint16_t)(get_chip_id() >> 32)); //print High 2 bytes
  Serial.printf("%08X\n", (uint32_t)get_chip_id()); //print Low 4bytes.
}

void loop() {

  while (1) {
    //Sensores reales
    display.clear();
    bme280_temp = bme280_get_temp();
    bme280_pres = bme280_get_pres();
    light = luz_get_value();
    mq135 = mq135_get_value();
    mq132 = mq132_get_value();
    sound = sound_get_value();

    oled_temp(bme280_temp);
    oled_pres(bme280_pres);
    oled_luz(light);
    oled_mq135(mq135);
    oled_mq132(mq132);
    oled_sound(sound);
    display.display();

    //accel_getdata();


    delay(10);

  }
}


