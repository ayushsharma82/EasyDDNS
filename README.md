# EasyDDNS
An Easy to Use ESP8266 DDNS Update Client Library.

This Library is Created to Update your DDNS Domains with your ESP8266. The EasyDDNS Library can be Implemented in your Major Projects too as a Sidekick. It is Independent and Does not Interfare with rest of the Working of your Code on ESP8266.

Currently EasyDDNS Library Supports DuckDNS and No-ip Only. More DDNS Services Coming Soon. Suggestions Appreciated.


Find More about DDNS: [WiKipedia](https://en.wikipedia.org/wiki/Dynamic_DNS)

# How to Install
###### Directly Through Arduino IDE
Go to Sketch > Include Library > Library Manager > Search for "EasyDDNS" > Install

###### Mannual Install

For Windows: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Documents>Arduino>Libraries>{Place "EasyDDNS" folder Here}

For Linux: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Sketchbook>Libraries>{Place "EasyDDNS" folder Here}

###### Mannually through IDE

Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip), Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

# Dependancies
This Library is Dependent on [ESP8266 Core Library](https://github.com/esp8266/Arduino) to Function Properly.
Make Sure you Install Both EasyDDNS and ESP8266 Core Library to make this Work.

# How to Implement
EasyDDNS Library uses only 4 Lines of Code to run the requested update server on your ESP8266.

Here is how you can do:

- Add `#include<EasyDDNS.h>` in your Code.
- Use `EasyDDNS DDNS;` to setup name for methods.
- Use `DDNS.service("duckdns");` in setup() and input "duckdns" or "noip" according to your preference.
- Add `DDNS.DuckClient("domain","token");` or `DDNS.NoipClient("domain","username","password");` according to above Line of Code.(You can't use both at once.)
- Atlast, Add `DDNS.update(10000);` in loop() to check for New Public IP after desired 'interval'

**2 Ready to Use Examples are Provided with Library for DuckDNS and No-ip Respectivly.**

# Support Me
Liked this Library? You may want to Support me by sending me a :beer: [Beer](https://www.paypal.me/ayushsharma82/5).
