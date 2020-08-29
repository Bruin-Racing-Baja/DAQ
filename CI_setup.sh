#!/bin/bash

# Script to install all non-standard libaries that your code depends on
# (libraries you are using in your ARDUINO_LIBS environemnt variable)
mkdir dependencies
platformio lib --storage-dir dependencies install "Adafruit GFX Library"
export ARDUINO_LIB=dependencies/