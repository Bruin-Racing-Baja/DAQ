/**
 *  File: screen_test.cpp
 *
 *  Author: Thomas Kost
 *
 *  Date: 07 August 2020
 *
 *  @brief testing the screen object
 *
 */

#include <Arduino.h>
#include <screen.h>

#include <screen.cpp>

OLED_Screen oled_screen;

void setup() {
    Serial.begin(9600);
    Serial.println("Screen Object Test");
}

void loop() {
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('t');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('e');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('s');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('t');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('i');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('n');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.addData('g');
    oled_screen.printScreen();
    delay(1000);
    oled_screen.cursorRight();
    oled_screen.printScreen();
    delay(1000);
    oled_screen.cursorRight();
    oled_screen.printScreen();
    delay(1000);
    oled_screen.cursorLeft();
    oled_screen.printScreen();
    delay(1000);
    oled_screen.cursorLeft();
    oled_screen.printScreen();
    delay(1000);
    oled_screen.deleteData();
    oled_screen.deleteData();
    oled_screen.deleteData();
    oled_screen.deleteData();
    oled_screen.deleteData();
    oled_screen.deleteData();
    oled_screen.deleteData();
}
