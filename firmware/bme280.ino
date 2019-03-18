//BME280 de Adafruit

//Conexiones de este periférico:
//BME   -->   ESP32
//VIN   -->   3.3V
//GND   -->   GND
//SCK   -->   15 (SCL)
//SDI   -->   4 (SDA)

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void bme280_setup() {
  bme.begin();
}


float bme280_get_temp() {
  float temp = bme.readTemperature();
  //Serial.print("Temperature = "); Serial.print(temp); Serial.println(" *C");
  return temp;
}

float bme280_get_hum() {
  float humedad = bme.readHumidity();
  //Serial.print("Humedad = "); Serial.print(humedad); Serial.println(" %");
  return humedad;
}

float bme280_get_alt() {
  float altitud = bme.readAltitude(SEALEVELPRESSURE_HPA);
  //Serial.print("Altitud = "); Serial.print(altitud);   Serial.println(" %");
  return altitud;
}

float bme280_get_pres() {
  float presion = bme.readPressure() / 100.0F;
  //Serial.print("Presion = ");  Serial.print(presion);  Serial.println(" %");
  return presion;
}



