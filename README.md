# EasyDDNS

<p>
<!-- <img src="https://img.shields.io/travis/com/ayushsharma82/EasyDDNS.svg?style=for-the-badge" />
&nbsp; -->
<img src="https://img.shields.io/github/last-commit/ayushsharma82/EasyDDNS.svg?style=for-the-badge" />
&nbsp;
<img src="https://img.shields.io/github/license/ayushsharma82/EasyDDNS.svg?style=for-the-badge" />
&nbsp;
<a href="https://www.buymeacoffee.com/6QGVpSj" target="_blank"><img src="https://img.shields.io/badge/Buy%20me%20a%20coffee-%245-orange?style=for-the-badge&logo=buy-me-a-coffee" /></a>
</p>

<br>

An easy to use DDNS Update Client library for ESP8266 & ESP32.

EasyDDNS Library can be implemented in your major projects as a sidekick. It is independent and does not interfare with rest of your code.

#### Supported DDNS Providers:
- DuckDNS
- No-ip
- DynDNS
- Dynu
- ENom
- all-inkl
- selfhost.de
- strato

If you don't know what's DDNS, then you can find more info about DDNS here: [WiKipedia](https://en.wikipedia.org/wiki/Dynamic_DNS)

<br>

## How to Install
###### (Best Method) Directly Through Arduino IDE
Go to Sketch > Include Library > Library Manager > Search for "EasyDDNS" > Install

###### Manual Install

For Windows: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Documents>Arduino>Libraries>{Place "EasyDDNS" folder Here}

For Linux: Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip) and extract the .zip in Sketchbook>Libraries>{Place "EasyDDNS" folder Here}

###### Manually through IDE

Download the [Repository](https://github.com/ayushsharma82/EasyDDNS/archive/master.zip), Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

<br>

## Dependencies

#### For ESP8266:
- [ESP8266 Arduino Core](https://github.com/esp8266/Arduino)

#### For ESP32:
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)

<br>

## Examples
EasyDDNS Library uses only 3 lines of code to run the requested update server on your ESP8266 or ESP32.

##### DynDNS:<br>

```
#include <EasyDDNS.h>
#include <ESP8266WiFi.h>

const char* ssid = "your-ssid";
const char* password = "your-password";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP()); // Print the IP address
  server.begin();

  EasyDDNS.service("dyndns");    // Enter your DDNS Service Name - "duckdns" / "noip" / "dyndns" / "dynu"
  EasyDDNS.client("hostname","username","client-key");    // Enter ddns Hostname - Username - Client-key
}

void loop() {
  EasyDDNS.update(10000); // Check for New Ip Every 10 Seconds.
}
```

**You can find more examples for various other DDNS providers in the `examples` directory.**

<br>

## Support Me

If you like my work, You can always buy me a coffee :) , It supports my work and in return you get to keep a updated version of my libraries.

<br>
<a href="https://www.buymeacoffee.com/6QGVpSj" target="_blank"><img src="https://img.shields.io/badge/Buy%20me%20a%20coffee-%245-orange?style=for-the-badge&logo=buy-me-a-coffee" /></a>
