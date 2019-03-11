#include <WiFi.h>


const char* ssid     = "sindormir.net2";
const char* password = "espaciomiscela";


static void wifi_setup() {
  Serial.println("Connecting...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


