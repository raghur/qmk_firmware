#!/bin/bash
RPIMNT="/run/media/$USER/RPI-RP2"
KEYBD="converter/adafruit_rp2040_usbh"
KEYMAP="test"
UF2=".build/${KEYBD//\//_}_$KEYMAP.uf2"
BUILD="util/docker_build.sh"


$BUILD $KEYBD:$KEYMAP:uf2
read -p "Flash firmware? (press CTRL-Pause to enter bootloader mode) (y/N): " c && [[ "$c" =~ ^[Yy]$ ]] || exit 0

QMK_REV=$(git rev-parse --short HEAD)
ADAFRUIT_RP2040_REV=$(cd keyboards/$KEYBD; git rev-parse --short HEAD)
TAG="$QMK_REV.$ADAFRUIT_RP2040_REV"
TAGGED_UF2=${UF2//.uf2/.$TAG.uf2}
LATEST_UF2=${UF2//.uf2/.latest.uf2}
# copy to tagged versions
cp "$UF2" "$TAGGED_UF2"
cp "$UF2" "$LATEST_UF2"

# flash now
while [ ! -r "$RPIMNT" ]; do
    echo "Waiting for RPI2 mount..."
    sleep 5;
done;
cp "$UF2" "$RPIMNT"
