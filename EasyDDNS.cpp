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

Version 1.0.0
*/

#include "EasyDDNS.h"

void EasyDDNS::service(String ddns_service){
  ddns_choice = ddns_service;
}

void EasyDDNS::DuckClient(String ddns_duck_domain,String ddns_token){
  duck_domain = ddns_duck_domain;
  duck_token = ddns_token;
}

void EasyDDNS::NoipClient(String ddns_noip_domain, String ddns_username, String ddns_password){
  noip_domain = ddns_noip_domain;
  noip_u = ddns_username;
  noip_p = ddns_password;
}

void EasyDDNS::update(unsigned long ddns_update_interval){

    interval = ddns_update_interval;

    unsigned long currentMillis = millis(); // Calculate Elapsed Time & Trigger
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

// ######## GENERATE UPDATE URL ######## //
        if(String(ddns_choice) == "duckdns"){
          update_url = "http://www.duckdns.org/update?domains="+duck_domain+"&token="+duck_token+"&ip=";}
        else if(String(ddns_choice) == "noip"){
          update_url = "http://"+noip_u+":"+noip_p+"@dynupdate.no-ip.com/nic/update?hostname="+noip_domain+"&myip="+new_ip+"";}
        else{
          Serial.println("## INPUT CORRECT DDNS SERVICE NAME ##");}

// ######## GET PUBLIC IP ######## //
        HTTPClient http;
        http.begin("http://ipv4bot.whatismyipaddress.com/");
        int httpCode = http.GET();
        if(httpCode > 0) {
          if(httpCode == HTTP_CODE_OK) {
                new_ip = http.getString();
              }
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
