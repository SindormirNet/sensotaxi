#include <Adafruit_GPS.h>
#include <HardwareSerial.h>

#define GPSECHO  false


HardwareSerial GPSSerial(1);
Adafruit_GPS GPS(&GPSSerial);


void gps_setup()  {
  GPSSerial.begin(9600, SERIAL_8N1, 35, 34);

  //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_OFF);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  while (GPSSerial.available())
    GPSSerial.read();

  delay(1000);
  GPS.sendCommand("$PMTK622,1*29");
  Serial.println("----------------------------------------------------");
}


void gps_printdata() {
  if (GPSSerial.available()) {
    char c = GPSSerial.read();
    Serial.write(c);
  }
  /*if (Serial.available()) {
    char c = Serial.read();
    GPSSerial.write(c);
    }*/

}

void gps_printdata2() {
  static unsigned long timer;

  char c = GPS.read();

  if (GPS.newNMEAreceived()) {
    //Serial.println(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return; // we can fail to parse a sentence in which case we should just wait for another
  }
  
  if (timer > millis()) timer = millis();

  if (millis() - timer > 5000) {
    timer = millis(); // reset the timer
    Serial.print("\nTime: ");
    Serial.print(GPS.hour, DEC); Serial.print(':');
    Serial.print(GPS.minute, DEC); Serial.print(':');
    Serial.print(GPS.seconds, DEC); Serial.print('.');
    Serial.println(GPS.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPS.day, DEC); Serial.print('/');
    Serial.print(GPS.month, DEC); Serial.print("/20");
    Serial.println(GPS.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPS.fix);
    Serial.print(" quality: "); Serial.println((int)GPS.fixquality);
    if (GPS.fix) {
      Serial.print("Location: ");
      Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
      Serial.print(", ");
      Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
      Serial.print("Speed (knots): "); Serial.println(GPS.speed);
      Serial.print("Angle: "); Serial.println(GPS.angle);
      Serial.print("Altitude: "); Serial.println(GPS.altitude);
      Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
    }
  }
}

