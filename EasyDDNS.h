/*
EasyDDNS Library for ESP8266 or ESP32
See the README file for more details.

Written in 2017 by Ayush Sharma. Licensed under MIT.
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
  void client(String ddns_domain, String ddns_username, String ddns_password = "");
  void update(unsigned long ddns_update_interval, bool use_local_ip = false);

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
