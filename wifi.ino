#include <WiFi.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;

const char* server   = "sindormir.net";
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

  String get_string = "GET https://sindormir.net/~syvic/sensortaxi";
  String get_params = String ("?id=" + String(get_chip_id()) + 
                              "&temp="  + bme280_get_temp() + 
                              "&hum="  + bme280_get_hum() + 
                              "&alt="  + bme280_get_alt() + 
                              "&pres="  + bme280_get_pres() + 
                              "&ligth="  + luz_get_value() + 
                              "&mq135="  + mq135_get_value() + 
                              "&mq132="  + mq132_get_value() + 
                              "&sound="  + sound_get_value() + 
                              "&bounce="  + accel_get_bounche() + 
                              "&gps_date=" + gps_get_date() +
                              "&gps_hour=" + gps_get_hour() +
                              "&gps_lat=" + gps_get_latitude() +
                              "&gps_long=" + gps_get_longitude() +
                              "&gps_alt=" + gps_get_altitude()
                              );
  String http_version = " HTTP/1.0";

  //client.setCACert(test_root_ca);
  //client.setCertificate(test_client_key); // for client verification
  //client.setPrivateKey(test_client_cert);  // for client verification

  Serial.print("Conectando al server...");
  if (client.connect(server, 443)) {
    Serial.println("OK!");

    client.println(String (get_string + get_params + http_version));
    Serial.println(String (get_string + get_params + http_version));

    client.println("Host: sindormir.net");
    client.println("Connection: close");
    client.println();

    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }

    // Leemos los datos de respuesta del servidor
    Serial.print("Recibido desde el server: ");
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }
    Serial.println();

    client.stop();

  }
  else {
    Serial.println("Fallo!");
  }
}

