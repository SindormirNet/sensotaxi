//Conexiones de este periférico:
//GPS   -->   ESP32
//VIN   -->   5V
//GND   -->   GND
//RX    -->   34
//TX    -->   resistencia 1K  --> 35

#include <Adafruit_GPS.h>
#include <HardwareSerial.h>

//#define GPSECHO  false

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


String gps_get_hour() {
  String result = String (GPS.hour) + ':' + String (GPS.minute) + ':' + String(GPS.seconds) + '.' + String(GPS.milliseconds);
  return result;
}

String gps_get_date() {
  String result = "20" + String(GPS.year) + '/' + String(GPS.month) + '/' + String (GPS.day, DEC);
  return result;
}

String gps_get_latitude() {
  if (GPS.lat == 'N') return String((convertDegMinToDecDeg(GPS.latitude) / 1), 8);
  else                return String((-convertDegMinToDecDeg(GPS.latitude) / 1), 8);
}

String gps_get_longitude() {
  if (GPS.lon == 'E') return String((convertDegMinToDecDeg(GPS.longitude) / 1), 8);
  else                return String((-convertDegMinToDecDeg(GPS.longitude) / 1), 8);
}


String gps_get_altitude() {
  return String(GPS.altitude);
}



//Resultado de ejecución:
// 0 -> sin error y FIX
// 1 -> sin error pero no FIX
// 2 -> No data
unsigned int gps_printdata() {
  static unsigned long timer;

  char c = GPS.read();

  if (GPS.newNMEAreceived()) {
    //Serial.println(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return 2; // we can fail to parse a sentence in which case we should just wait for another
  }

  if (timer > millis()) timer = millis();

  if (millis() - timer > 5000) {
    timer = millis(); // reset the timer
    //Serial.print("\nTime: ");
    //Serial.print(GPS.hour, DEC); Serial.print(':');
    //Serial.print(GPS.minute, DEC); Serial.print(':');
    //Serial.print(GPS.seconds, DEC); Serial.print('.');
    //Serial.println(GPS.milliseconds);
    //Serial.print("Date: ");
    //Serial.print(GPS.day, DEC); Serial.print('/');
    //Serial.print(GPS.month, DEC); Serial.print("/20");
    //Serial.println(GPS.year, DEC);
    //Serial.print("Fix: "); Serial.print((int)GPS.fix);
    //Serial.print(" quality: "); Serial.println((int)GPS.fixquality);

    if (GPS.fix) {
      Serial.print("Location: ");
      Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
      Serial.print(", ");
      Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
      //Serial.print("Speed (knots): "); Serial.println(GPS.speed);
      //Serial.print("Angle: "); Serial.println(GPS.angle);
      //Serial.print("Altitude: "); Serial.println(GPS.altitude);
      //Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
      return 0;
    }
    else {
      return 1;
    }
  }
}

