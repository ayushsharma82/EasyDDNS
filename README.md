# EasyDDNS
An Easy to Use ESP8266 DDNS Update Client Library.

This Library is created to update your DDNS domains with your ESP8266 Or ESP32. The EasyDDNS Library can be implemented in your major projects as a Sidekick. It is independent and does not interfare with rest of your code.

**Currently EasyDDNS Library Supports DuckDNS, No-ip, DynDNS, Dynu, ENom.**


Find More about DDNS: [WiKipedia](https://en.wikipedia.org/wiki/Dynamic_DNS)

# How to Install
###### Directly Through Arduino IDE
Go to Sketch > Include Library > Library Manager > Search for "EasyDDNS" > Install

###### Manual Install

For Windows: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Documents>Arduino>Libraries>{Place "EasyDDNS" folder Here}

For Linux: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Sketchbook>Libraries>{Place "EasyDDNS" folder Here}

###### Manually through IDE

Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip), Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

# Dependencies
This Library is Dependent on [ESP8266 Core Library](https://github.com/esp8266/Arduino) or [Arduino core for ESP32](https://github.com/espressif/arduino-esp32) to Function Properly.
Make Sure you Install Both EasyDDNS and ESP8266 Core Library (or Arduino core for ESP32) to make this Work.

# How to Implement
EasyDDNS Library uses only 3 Lines of Code to run the requested update server on your ESP8266 or ESP32.

###### Here is How you can use the Library:<br>

**For V1.5.0:**<br>
- Add `#include<EasyDDNS.h>` in your Code at Top.
- Use `EasyDDNS.service("");` in setup() to select your ddns service - "duckdns" / "noip" / "dyndns" / "dynu" / "enom" / "all-inkl" / "selfhost.de".


Now in setup() again, For **DuckDNS** Use `EasyDDNS.client("domain","token");`<br>
<br>
OR
<br>
For **DynDNS** Use `EasyDDNS.client("hostname","username","client-key");`<br>
<br>
OR
<br>
For **No-ip / Dynu / all-inkl / selfhost.de**, Use `EasyDDNS.client("hostname","username","password");`<br>
<br>
OR
<br>
For **enom**, Use `EasyDDNS.client("host","domain","password");`<br>
where `host` is something like `www`, and `domain` can be `example.com` <br>

- Atlast Use `EasyDDNS.update(10000);` in loop() to set Interval to Check for New Public IP.
<br>
OR
<br>
Use `EasyDDNS.update(10000, true);` in loop() to set Interval to Check for New Local Network IP so can use DDNS for devices that don't support mDNS to access within local network. 

**5 Ready to Use Examples are Provided with Library for DuckDNS, DynDNS, Dynu, No-ip & enom.**

# Support Me
Liked this Library? You can Support me by sending me a :beer: [Beer](https://www.paypal.me/ayushsharma82/5).
