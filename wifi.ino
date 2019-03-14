#include <WiFi.h>
//#include <WiFiClientSecure.h> //[SSL]
#include <WiFiClient.h>

//WiFiClientSecure client; //[SSL]
WiFiClient client;

//const char* server   = "sindormir.net"; //[SSL]
const char* server   = "sensortaxi.asako.org";
extern const char* ssid;
extern const char* password;

static void wifi_setup() {
  Serial.print("Conectando...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWiFi conectada. IP: ");
  Serial.println(WiFi.localIP());
}


void wifi_connect() {
  String get_params;

  get_params.reserve(300);

  //String get_string = "GET https://sindormir.net/~syvic/sensortaxi";//[SSL]
  String get_string = "GET http://sensortaxi.asako.org/entradato.php";
  String http_version = " HTTP/1.0";


  if (gps_data_valid == 0) {
    get_params = String ("?id=" + String(get_chip_id())     +
                         "&temp="     + bme280_temp   +
                         "&hum="      + bme280_get_hum()    +
                         "&alt="      + bme280_get_alt()    +
                         "&pres="     + bme280_pres   +
                         "&ligth="    + light     +
                         "&mq135="    + mq135   +
                         "&mq132="    + mq132   +
                         "&sound="    + sound   +
                         "&bounce="   + accel_get_bounche() +
                         "&gps_date=" + gps_get_date()      +
                         "&gps_hour=" + gps_get_hour()      +
                         "&gps_lat="  + gps_get_latitude()  +
                         "&gps_long=" + gps_get_longitude() +
                         "&gps_alt="  + gps_get_altitude());
  }
  else {
    get_params = String ("?id=" + String(get_chip_id())     +
                         "&temp="    + bme280_temp   +
                         "&hum="     + bme280_get_hum()    +
                         "&alt="     + bme280_get_alt()    +
                         "&pres="    + bme280_pres   +
                         "&ligth="   + light     +
                         "&mq135="   + mq135   +
                         "&mq132="   + mq132   +
                         "&sound="   + sound   +
                         "&bounce="  + accel_get_bounche() +
                         "&gps_date=0&gps_hour=0&gps_lat=0&gps_long=0&gps_alt=0");
  }


  //client.setCACert(test_root_ca);
  //client.setCertificate(test_client_key); // for client verification
  //client.setPrivateKey(test_client_cert);  // for client verification

  //Serial.print("Conectando al server...");
  //if (client.connect(server, 443)) { //[SSL]
  if (client.connect(server, 80)) {
    //Serial.println("OK!");

    client.println(String (get_string + get_params + http_version));
    //Serial.println(String (get_string + get_params + http_version));

    client.println("Host: sensortaxi.asako.org");
    //client.println("Host: sindormir.net"); //[SSL]
    client.println("Connection: close");
    client.println();

    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }

    // Leemos los datos de respuesta del servidor
    //Serial.println("Recibido desde el server: ");
    while (client.available()) {
      char c = client.read();
      //Serial.write(c);
    }
    //Serial.println();

    client.stop();

  }
  else {
    //Serial.println("Fallo!");
  }
}

