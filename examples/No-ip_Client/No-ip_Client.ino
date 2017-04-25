/*
######### Noip Update Client for ESP8266 ##########
This Example Explains the Use of EasyDDNS Library with No-ip Service
and Checks for New Public IP Every 10 Seconds.

Author: Ayush Sharma
*/
#include <EasyDDNS.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "your-ssid";
const char* password = "your-password";

WiFiServer server(80);

EasyDDNS DDNS;

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

DDNS.service("noip");    // Enter your DDNS Service Name - "duckdns" / "noip"
DDNS.NoipClient("domain","username","password");    // Enter ddns Domain & Username & Password | Example - "esp.duckdns.org","username", "password"
}

void loop() {
DDNS.update(10000); // Check for New Ip Every 10 Seconds.
}
