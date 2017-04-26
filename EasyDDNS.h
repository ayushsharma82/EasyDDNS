/*
  EasyDDNS Library for ESP8266
  See the README file for more details.

  Written in 2017 by Ayush Sharma.

  This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License:
  http://creativecommons.org/licenses/by-sa/4.0/

  Version 1.5.0

  Changelog:
  Version 1.0.0 - Made EasyDDNS Library for No-ip and DuckDNS
  Version 1.5.0 - Optimized Library and Added Dyndns & Dynu
*/

#ifndef EasyDDNS_H
#define EasyDDNS_H

#include "Arduino.h"
#include "stdlib_noniso.h"
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"

#define HARDWARE "esp8266"

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
