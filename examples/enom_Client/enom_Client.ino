/*
######### ENom Update Client for ESP8266 ##########
This Example Explains the Use of EasyDDNS Library with No-ip Service
and Checks for New Public IP Every 10 Seconds.

Author: Ayush Sharma
*/
#include <EasyDDNS.h>
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ESP32)
  #include <WiFi.h>
#endif

const char* ssid = "your-ssid";
const char* password = "your-password";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP()); // Print the IP address
  server.begin();

  EasyDDNS.service("enom");    // Enter your DDNS Service Name - "duckdns" / "noip" / "enom"
  EasyDDNS.client("www","example.com","password");    // Enter ddns host & domain name & Password | Example - "www","example.com", "password"
}

void loop() {
  EasyDDNS.update(10000); // Check for New Ip Every 10 Seconds.
}
