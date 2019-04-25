# EasyDDNS
An Easy to Use ESP8266 and ESP32 DDNS Update Client Library.

This Library is Created to Update your DDNS Domains with your ESP8266 and ESP32. The EasyDDNS Library can be Implemented in your Major Projects too as a Sidekick. It is Independent and Does not Interfare with rest of the Working of your Code on ESP8266 and ESP32.

**Currently EasyDDNS Library Supports DuckDNS, No-ip, DynDNS, Dynu, enom.**


Find More about DDNS: [WiKipedia](https://en.wikipedia.org/wiki/Dynamic_DNS)

# How to Install
###### Directly Through Arduino IDE
Go to Sketch > Include Library > Library Manager > Search for "EasyDDNS" > Install

###### Manual Install

For Windows: Download the [Repository](https://github.com/vivian-ng/EasyDDNS/archive/master.zip) and extract the .zip in Documents>Arduino>Libraries>{Place "EasyDDNS" folder Here}

For Linux: Download the [Repository](https://github.com/vivian-ng/EasyDDNS/archive/master.zip) and extract the .zip in Sketchbook>Libraries>{Place "EasyDDNS" folder Here}

###### Manually through IDE

Download the [Repository](https://github.com/vivian-ng/EasyDDNS/archive/master.zip), Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

# Dependencies
This Library is Dependent on [ESP8266 Core Library](https://github.com/esp8266/Arduino) or [Arduino core for ESP32](https://github.com/espressif/arduino-esp32) to Function Properly.
Make Sure you Install Both EasyDDNS and ESP8266 Core Library (or Arduino core for ESP32) to make this Work.

# How to Implement
EasyDDNS Library uses only 3 Lines of Code to run the requested update server on your ESP8266 or ESP32.

###### Here is How you can use the Library:<br>

**For V1.5.0r1:**<br>
- Add `#include<EasyDDNS.h>` in your Code at Top.
- Use `EasyDDNS.service("");` in setup() to select your ddns service - "duckdns" / "noip" / "dyndns" / "dynu" / "enom".

Now in setup() again, For **DuckDNS** Use `EasyDDNS.client("domain","token");`<br>
OR<br>
For **DynDNS** Use `EasyDDNS.client("hostname","username","client-key");`<br>
OR<br>
For **No-ip / Dynu**, Use `EasyDDNS.client("hostname","username","password");`<br>
OR<br>
For **enom**, Use `EasyDDNS.client("host","domain","password");`<br>
where `host` is something like `www`, and `domain` can be `example.com` <br>

- Atlast Use `EasyDDNS.update(10000);` in loop() to set Interval to Check for New Public IP.

**5 Ready to Use Examples are Provided with Library for DuckDNS, DynDNS, Dynu, No-ip & enom.**

# Support original author
Liked this Library? You can the original author by sending a :beer: [Beer](https://www.paypal.me/ayushsharma82/5).
