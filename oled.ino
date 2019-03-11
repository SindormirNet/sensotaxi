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
  display.drawString(5, 10, "SENSOR TAXI\nTest 1");
  display.display();
  //delay(2000);
}


void oled_luz() {
  int luz = analogRead(37);
  
  display.drawProgressBar(0, 24, 100, 10, luz * 100 / 4096);
  display.setFont(ArialMT_Plain_10);
  display.drawString(105, 24, String(luz));
}

void oled_mq135(int value) {
  display.drawProgressBar(0, 36, 100, 10, value * 100 / 4096);
  display.setFont(ArialMT_Plain_10);
  display.drawString(105, 36, String(value));
}

void oled_progress(int progress) {
  display.drawProgressBar(0, 48, 100, 10, progress);
  display.setFont(ArialMT_Plain_10);
  display.drawString(105, 48, String(progress));

}

void oled_progress2(int progress) {
  display.drawProgressBar(0, 12, 100, 10, progress);
  display.setFont(ArialMT_Plain_10);
  display.drawString(105, 12, String(progress));
}

void oled_progress3(int progress) {
  display.drawProgressBar(0, 0, 100, 10, progress);
  display.setFont(ArialMT_Plain_10);
  display.drawString(105, 0, String(progress));
}

