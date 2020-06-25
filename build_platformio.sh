#!/bin/bash

set -euo pipefail

pio ci --lib=. --board esp12e "examples/DDNS_Client"
pio ci --lib=. --board esp32dev "examples/DDNS_Client"
