#!/bin/bash

set -euo pipefail

pio ci --lib=. --board esp12e "examples/DynDNS_Client"
pio ci --lib=. --board esp32dev "examples/DynDNS_Client"
