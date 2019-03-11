#include <WiFi.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;

const char*  server = "sindormir.net";
const char* ssid     = "sindormir.net2";
const char* password = "espaciomiscela";


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
  String get_params = String ("?id=" + String(get_chip_id()) + "&ligth=" + analogRead(37) + "&gas=" + analogRead(MQ135_PIN) );
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

    Serial.println("---------------------------");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("Cabeceras recibidas");
        break;
      }
      else {
        Serial.print("@");
      }
    }

    // Leemos los datos de respuesta del servidor
    Serial.println("---------------------------");
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    client.stop();

  }
  else {
    Serial.println("Fallo!");
  }
}

