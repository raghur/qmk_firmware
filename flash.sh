#!/bin/bash
set -euo pipefail

RAM_LIMIT=2173

pushd keyboards/converter/usb_usb/keymaps/raghu 
qmk json2c raghu.json > keymap.c
sed -i '1 a #include "custom.h"' keymap.c
popd
RUNTIME=podman util/docker_build.sh converter/usb_usb/pro_micro:raghu
RAM=$(avr-size -C .build/*_pro_micro_raghu.elf  |grep -Po "Data:\s+\d+" | grep -Po "\d+")
    echo "=================RAM: .data + .bss=$RAM================================="
if [ "$RAM" -gt "$RAM_LIMIT" ]; then
    echo "Your firmware is using too much RAM; ; known good=$RAM_LIMIT "
    echo "===================================================================="
    exit 1
fi
RUNTIME=podman util/docker_build.sh converter/usb_usb/pro_micro:raghu:flash

