#!/bin/bash
set -euo pipefail

QMK=$(qmk env QMK_HOME)

pushd keyboards/converter/usb_usb/keymaps/raghu 
qmk json2c raghu.json > keymap.c
sed -i '1 a #include "custom.h"' keymap.c
popd
RUNTIME=podman util/docker_build.sh converter/usb_usb/pro_micro:raghu:avrdude


