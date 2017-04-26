/*
######### DuckDNS Update Client for ESP8266 ##########
This Example Explains the Use of EasyDDNS Library with Dynu Service
and Checks for New IP Every 10 Seconds.

Author: Ayush Sharma
*/
#include <EasyDDNS.h>
#include <ESP8266WiFi.h>

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

EasyDDNS.service("dynu");    // Enter your DDNS Service Name - "duckdns" / "noip" / "dyndns" / "dynu"
EasyDDNS.client("hostname","username","password");    // Enter ddns Hostname - Username - Client-key
}

void loop() {
EasyDDNS.update(10000); // Check for New Ip Every 10 Seconds.
}
