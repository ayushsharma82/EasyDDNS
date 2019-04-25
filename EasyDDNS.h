/*
// ##### REQUIRED LIBRARIES IN SKETCH ##### //
 -- for ESP8266 --
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"

-- for ESP32 --
#include "WiFi.h"
#include "HTTPClient.h"

*/

/*
EasyDDNS Library for ESP8266 and ESP32
See the README file for more details.

Original EasyDDNS Library for ESP8266 written in 2017 by Ayush Sharma.
Modified by Vivian Ng in 2019.

This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License:
http://creativecommons.org/licenses/by-sa/4.0/

Version 1.5.0r1
Changelog:
Version 1.0.0 - Made EasyDDNS Library for No-ip and DuckDNS
Version 1.5.0 - Optimized Library and Added Dyndns & Dynu
Version 1.5.0r1 - Added ESP32 support and enom DNS provider.
*/

#ifndef EasyDDNS_H
#define EasyDDNS_H

#include "Arduino.h"
#include "stdlib_noniso.h"

#if defined(ESP8266)
  #include "ESP8266WiFi.h"
  #include "ESP8266HTTPClient.h"
  #define HARDWARE "esp8266"
#elif defined(ESP32)
  #include "WiFi.h"
  #include "HTTPClient.h"
  #define HARDWARE "esp32"
#endif


class EasyDDNSClass{
public:
  void service(String ddns_service);
  void client(String ddns_domain, String ddns_username,String ddns_password = "");
  void update(unsigned long ddns_update_interval);

private:
  unsigned long interval;
  unsigned long previousMillis;

  String new_ip;
  String old_ip;
  String update_url;
  String ddns_u;
  String ddns_p;
  String ddns_d;
  String ddns_choice;
};
extern EasyDDNSClass EasyDDNS;
#endif
