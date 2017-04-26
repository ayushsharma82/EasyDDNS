/*
// ##### REQUIRED LIBRARIES IN SKETCH ##### //
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
*/

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

#include "EasyDDNS.h"

void EasyDDNSClass::service(String ddns_service){
  ddns_choice = ddns_service;
}

void EasyDDNSClass::client(String ddns_domain, String ddns_username, String ddns_password){
  ddns_d = ddns_domain;
  ddns_u = ddns_username;
  ddns_p = ddns_password;
}

void EasyDDNSClass::update(unsigned long ddns_update_interval){

    interval = ddns_update_interval;

    unsigned long currentMillis = millis(); // Calculate Elapsed Time & Trigger
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

// ######## GENERATE UPDATE URL ######## //
        if(ddns_choice == "duckdns"){
          update_url = "http://www.duckdns.org/update?domains="+ddns_d+"&token="+ddns_u+"&ip=";}
        else if(ddns_choice == "noip"){
          update_url = "http://"+ddns_u+":"+ddns_p+"@dynupdate.no-ip.com/nic/update?hostname="+ddns_d+"&myip="+new_ip+"";}
        else if(ddns_choice == "dyndns"){
          update_url = "http://"+ddns_u+":"+ddns_p+"@members.dyndns.org/v3/update?hostname="+ddns_d+"&myip="+new_ip+"";}
        else if(ddns_choice == "dynu"){
          update_url = "http://api.dynu.com/nic/update?hostname="+ddns_d+"&myip="+new_ip+"&username="+ddns_u+"&password="+ddns_p+"";}
        else{
          Serial.println("## INPUT CORRECT DDNS SERVICE NAME ##");
          return;
         }

// ######## GET PUBLIC IP ######## //
        HTTPClient http;
        http.begin("http://ipv4bot.whatismyipaddress.com/");
        int httpCode = http.GET();
        if(httpCode > 0) {
          if(httpCode == HTTP_CODE_OK) {
                new_ip = http.getString();
              }
        }else{
          http.end();
          return;
        }
        http.end();

// ######## CHECK & UPDATE ######### //
    if(old_ip != new_ip){

       HTTPClient http;
       http.begin(update_url);
       int httpCode = http.GET();
       if(httpCode > 0) {
         old_ip = new_ip;
        }
       http.end();
     }

    }
}

EasyDDNSClass EasyDDNS;
