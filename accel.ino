//ADXL345 Adafruit

//Conexiones de este periférico:
//ADXL   -->   ESP32
//GND    -->   GND
//VCC    -->   3.3V
//SDA    -->   21
//SCL    -->   22

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12346);


int accel_get_bounche() {

  return 0;
}

void accel_setup() {
  if (!accel.begin()) {
    Serial.println("No se ha detectado el ADXL345");
    //while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
}


void accel_getdata() {
  sensors_event_t event; 
  accel.getEvent(&event);
 
  //Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.println(event.acceleration.z);
  delay(10);
}





