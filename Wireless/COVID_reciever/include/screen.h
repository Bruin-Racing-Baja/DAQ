/**
 *  File: screen.h
 *
 *  Author: Thomas Kost
 *
 *  Date: 07 August 2020
 *
 *  @brief contains screen object and state of the OLED SCREEN for COVID
 * Reciever
 *
 */
#ifndef OLED_SCREEN
#define OLED_SCREEN
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1305.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <string.h>

#define OLED_SCREEN_WIDTH 19
#define OLED_SCREEN_HEIGHT 4

#define OLED_CLK 13  // note this is using hardware SPI
#define OLED_MOSI 11
#define OLED_CS 10
#define OLED_DC 8
#define OLED_RESET 9

struct OLED_Screen {
    /**
     *  @brief constructor for the OLED screen manager uses pins defined above
     */
    OLED_Screen();

    /**
     *  @brief prints the screen
     */
    void printScreen();

    /**
     *  @brief add a character to the screen
     *  @param new_character character to be added to screen
     */
    void addData(char new_character);

    /**
     *  @brief delete a character from the screen
     */
    void deleteData();

    /**
     *  @brief move the cursor left
     */
    void cursorLeft();

    /**
     *  @brief move the cursor right
     */
    void cursorRight();

    /**
     *  @brief select the character the cursor is currently on
     *  @return character the cursor is currenly on
     */
    char cursorSelect();

    // data members
    int cursor_state_;
    char data_[OLED_SCREEN_HEIGHT * OLED_SCREEN_WIDTH];
    int screen_data_length_;
    int intitial_screen_data_length_;
    Adafruit_SSD1305 display_;
};

#endif