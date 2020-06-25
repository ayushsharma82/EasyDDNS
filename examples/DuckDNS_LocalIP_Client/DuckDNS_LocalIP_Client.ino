/*
######### DuckDNS Update with Local IP Client for ESP8266 ##########
This Example Explains the Use of EasyDDNS Library with DuckDNS Service
and Checks for a New local IP Every 10 Seconds.


Author: Ayush Sharma, with very minor changes by Clint Cooper 

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

EasyDDNS.service("duckdns");    // Enter your DDNS Service Name - "duckdns" / "noip"
EasyDDNS.client("domain","token");    // Enter ddns Domain & Token | Example - "esp.duckdns.org","1234567"
}

void loop() {
EasyDDNS.update(10000, true); // Check for New Ip Every 10 Seconds, pass in true to use local Wifi IP address
}
