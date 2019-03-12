#include <NeoPixelBus.h>

const uint16_t PixelCount = 8;
const uint8_t PixelPin = 2;

#define colorSaturation 64


NeoPixelBus<NeoGrbFeature, NeoEsp32I2s1800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);


void neopixel_setup() {
  strip.Begin();
  strip.Show();
}


void neopixel_all_on() {
  strip.SetPixelColor(0, red);
  strip.SetPixelColor(1, red);
  strip.SetPixelColor(2, green);
  strip.SetPixelColor(3, green);
  strip.SetPixelColor(4, blue);
  strip.SetPixelColor(5, blue);
  strip.SetPixelColor(6, white);
  strip.SetPixelColor(7, white);

  strip.Show();

}

void neopixel_all_off() {
  for (int i = 0; i < 8; i++) {
    strip.SetPixelColor(i, black);
  }
  strip.Show();
}

