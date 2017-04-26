# EasyDDNS
An Easy to Use ESP8266 DDNS Update Client Library.

This Library is Created to Update your DDNS Domains with your ESP8266. The EasyDDNS Library can be Implemented in your Major Projects too as a Sidekick. It is Independent and Does not Interfare with rest of the Working of your Code on ESP8266.

**Currently EasyDDNS Library Supports DuckDNS, No-ip, DynDNS, Dynu.**


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
EasyDDNS Library uses only 3 Lines of Code to run the requested update server on your ESP8266.

###### Here is How you can use the Library:<br>

**For V1.5.0:**<br>
- Add `#include<EasyDDNS.h>` in your Code at Top.
- Use `EasyDDNS.service("");` in setup() to select your ddns service - "duckdns" / "noip" / "dyndns" / "dynu".

Now in setup() again, For **DuckDNS** Use `EasyDDNS.client("domain","token");`<br>
OR<br>
For **DynDNS** Use `EasyDDNS.client("hostname","username","client-key");`<br>
OR<br>
For **No-ip / Dynu**, Use `EasyDDNS.client("hostname","username","password");`<br>

- Atlast Use `EasyDDNS.update(10000);` in loop() to set Interval to Check for New Public IP.

**4 Ready to Use Examples are Provided with Library for DuckDNS, DynDNS, Dynu & No-ip.**

# Support Me
Liked this Library? You can Support me by sending me a :beer: [Beer](https://www.paypal.me/ayushsharma82/5).
