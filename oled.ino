#include <Wire.h>
#include "SSD1306.h"

#define OLED_RESET 16
#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_ADDR 0x3C

SSD1306 display(OLED_ADDR, OLED_SDA, OLED_SCL);

void oled_init() {
  pinMode(OLED_RESET, OUTPUT);
  delay(50);
  digitalWrite(OLED_RESET, HIGH);
  display.init();
  display.flipScreenVertically();
}

void oled_intro() {
  display.clear();
  display.setFont(ArialMT_Plain_16); //24
  display.drawString(5, 10, "SENSOR TAXI\nEsperando Wifi");
  display.display();
}


void oled_temp(int temp) {
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "T:");
  display.drawProgressBar(12, 0, 28, 10, temp);
  display.drawString(44, 0, String(temp));
}

void oled_pres(int pres) {
  display.setFont(ArialMT_Plain_10);
  display.drawString(60, 0, "P:");
  display.drawProgressBar(72, 0, 28, 10, pres/10-50);
  display.drawString(105, 0, String(pres));
}


void oled_sound(int sonido) {

  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 12, "Snd:");
  
  display.drawProgressBar(25, 12, 75, 10, sonido * 100 / 4096);
  display.drawString(105, 12, String(sonido));
}

void oled_luz(int luz) {
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 24, "Lux:");
  
  display.drawProgressBar(25, 24, 75, 10, luz * 100 / 15000);
  
  display.drawString(105, 24, String(luz));
}

void oled_mq135(int value) {
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 36, "135:");
  
  display.drawProgressBar(25, 36, 75, 10, value * 100 / 4096);
  display.drawString(105, 36, String(value));
}

void oled_mq132(int value) {
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 48, "132:");
  
  display.drawProgressBar(25, 48, 75, 10, value * 100 / 4096);
  display.drawString(105, 48, String(value));

}

