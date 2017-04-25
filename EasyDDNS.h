/*
  EasyDDNS Library for ESP8266
  See the README file for more details.

  Written in 2017 by Ayush Sharma.

  This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License:
  http://creativecommons.org/licenses/by-sa/4.0/

  Version 1.0.0
*/

#ifndef EasyDDNS_H
#define EasyDDNS_H

#include "Arduino.h"
#include "stdlib_noniso.h"
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"

#define HARDWARE "esp8266"

class EasyDDNS{
public:
  void service(String ddns_service);
  void DuckClient(String ddns_duck_domain, String ddns_token);
  void NoipClient(String ddns_noip_domain, String ddns_username,String ddns_password);
  void update(unsigned long ddns_update_interval);

private:
  unsigned long interval;
  unsigned long previousMillis;
  
  String new_ip;
  String old_ip;
  String update_url;
  String noip_u;
  String noip_p;
  String noip_domain;
  String ddns_choice;
  String duck_token;
  String duck_domain;
};

#endif
