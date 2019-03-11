#include <BH1750FVI.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void luz_setup() {
  LightSensor.begin();  
}

int luz_get_value() {
  uint16_t lux = LightSensor.GetLightIntensity();
  Serial.print("Light: ");
  Serial.println(lux);
  return lux;
}
