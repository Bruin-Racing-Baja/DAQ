#!/bin/bash

# Script to install all non-standard libaries that your code depends on
# (libraries you are using in your ARDUINO_LIBS environemnt variable)
mkdir dependencies
platformio lib --storage-dir dependencies install "Adafruit GFX Library"

cd dependencies
git clone https://github.com/adafruit/Adafruit_SSD1305.git
cd -
PWD=$(pwd)
export ARDUINO_LIB="$PWD/dependencies"
echo $ARDUINO_LIB