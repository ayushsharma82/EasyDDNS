/*
EasyDDNS Library for ESP8266 or ESP32
See the README file for more details.

Written in 2017 by Ayush Sharma. Licensed under MIT.
*/

#ifndef EasyDDNS_H
#define EasyDDNS_H

#include "Arduino.h"
#include "stdlib_noniso.h"
#include <WiFiClientSecure.h>

#if defined(ESP8266)
  #include "ESP8266WiFi.h"
  #include "ESP8266HTTPClient.h"
  #define HARDWARE "esp8266"
#elif defined(ESP32)
  #include "WiFi.h"
  #include "HTTPClient.h"
  #define HARDWARE "esp32"
#endif


// Handler to notify user about new public IP
typedef std::function<void(const char* old_ip, const char* new_ip)> DDNSUpdateHandler;
typedef std::function<void(int httpCode, String errorMsg)> DDNSErrorHandler;

class EasyDDNSClass{
  public:
    void service(String ddns_service);
    void client(String ddns_domain, String ddns_username, String ddns_password = "", String ddns_identifier = "");
    void update(unsigned long ddns_update_interval, bool use_local_ip = false);

    // Callback
    void onUpdate(DDNSUpdateHandler handler) {
      _ddnsUpdateFunc = handler;
    }
    void onError(DDNSErrorHandler handler) {
      _ddnsErrorFunc = handler;
    }

  private:
    DDNSUpdateHandler _ddnsUpdateFunc = nullptr;
    DDNSErrorHandler _ddnsErrorFunc = nullptr;

    unsigned long interval;
    unsigned long previousMillis;

    String new_ip;
    String old_ip = "0.0.0.0";
    String update_url;
    String ddns_u;
    String ddns_p;
    String ddns_d;
    String ddns_id;
    String ddns_choice;
};
extern EasyDDNSClass EasyDDNS;
#endif
