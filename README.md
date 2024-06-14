# EasyDDNS

<br/>

**Notice: This library has been deprecated and is not going to be maintained.**

<br/>

<p>
<img src="https://img.shields.io/github/last-commit/ayushsharma82/EasyDDNS.svg?style=for-the-badge" />
&nbsp;
<img src="https://img.shields.io/github/actions/workflow/status/ayushsharma82/EasyDDNS/ci.yml?branch=master&style=for-the-badge" />
&nbsp;
<img src="https://img.shields.io/github/license/ayushsharma82/EasyDDNS?style=for-the-badge" />
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
- freemyip
- afraid.org
- OVH.com

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

## Example

```
#if defined(ESP8266)
  #include "ESP8266WiFi.h"
  #include "ESP8266HTTPClient.h"
#elif defined(ESP32)
  #include "WiFi.h"
  #include "HTTPClient.h"
#endif

#include <EasyDDNS.h>

const char * ssid = "your-ssid";
const char * password = "your-password";

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

  /*
    List of supported DDNS providers:
    - "duckdns"
    - "noip"
    - "dyndns"
    - "dynu"
    - "enom"
    - "all-inkl"
    - "selfhost.de"
    - "dyndns.it"
    - "strato"
    - "freemyip"
    - "afraid.org"
  */
  EasyDDNS.service("duckdns");

  /*
    For DDNS Providers where you get a token:
      Use this: EasyDDNS.client("domain", "token");
    
    For DDNS Providers where you get username and password: ( Leave the password field empty "" if not required )
      Use this: EasyDDNS.client("domain", "username", "password");
  */
  EasyDDNS.client("12345.duckdns.org", "token"); // Enter your DDNS Domain & Token

  // Get Notified when your IP changes
  EasyDDNS.onUpdate([&](const char* oldIP, const char* newIP){
    Serial.print("EasyDDNS - IP Change Detected: ");
    Serial.println(newIP);
  });
}

void loop() {
  // Check for new public IP every 10 seconds
  EasyDDNS.update(10000);
}
```

<br>

## Support Me

You can always buy me a coffee :) , It supports my work and in return you get to keep up-to-date version of my libraries.

<br>
<a href="https://www.buymeacoffee.com/6QGVpSj" target="_blank"><img src="https://img.shields.io/badge/Buy%20me%20a%20coffee-%245-orange?style=for-the-badge&logo=buy-me-a-coffee" /></a>
