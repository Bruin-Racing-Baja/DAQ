/**
 *  File: startupGUI.h
 *
 *  Author: Thomas Kost
 *
 *  Date: 26 August 2020
 *
 *  @brief Graphical interface for COVID Reciever, takes input and returns file
 * name
 *
 */

#ifndef STARTUP_GUI_H
#define STARTUP_GUI_H

#include <Arduino.h>
#include <screen.h>

#include <string>

class StartupGUI {
   public:
    /**
     *  @brief constructor for the startup gui--used for getting file name
     *  @param screen screen object that controls the OLED screen
     *  @param left_pin pin with button for moving left (pull down)
     *  @param right_pin pin with button for moving right (pull down)
     *  @param select_pin pin with button for selecting (pull down)
     *  @param backspace_pin pin with button for deleting entry (pull down)
     */
    StartupGUI(OLED_Screen& screen, uint8_t left_pin, uint8_t right_pin,
               uint8_t select_pin, uint8_t backspace_pin, uint8_t enter_pin, uint8_t max_name_length);

    /**
     *  @brief running function for GUI
     *  @return integer error code
     *  @param file_name character array that can hold the file
     *  @param name_length length of the array returned
     */
    int run(char* file_name, int& name_length);

   private:
    // member functions

    /**
     *  @brief do a digital read on the pin
     *  @return value of digital read
     *  @param pin_number pin to read
     */
    bool checkButtonStatus(int pin_number);

    /**
     *  @brief check that only a single button is pressed
     *  @return boolean on wether only one button pressed
     */
    bool checkSingleButtonPressed();

    // data members
    OLED_Screen screen_;
    uint8_t left_;
    uint8_t right_;
    uint8_t select_;
    uint8_t backspace_;
    uint8_t enter_;
    uint8_t max_name_length_;
};

#endif
