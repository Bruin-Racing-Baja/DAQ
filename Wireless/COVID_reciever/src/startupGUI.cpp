/**
 *  File: startupGUI.cpp
 *
 *  Author: Thomas Kost
 *
 *  Date: 28 August 2020
 *
 *  @brief Graphical interface for COVID Reciever, takes input and returns file
 * name
 *
 */
#include <startupGUI.h>

StartupGUI::StartupGUI(OLED_Screen& screen, uint8_t left_pin, uint8_t right_pin,
                       uint8_t select_pin, uint8_t backspace_pin,
                       uint8_t enter_pin, uint8_t max_name_length)
    : screen_(screen),
      left_(left_pin),
      right_(right_pin),
      select_(select_pin),
      backspace_(backspace_pin),
      enter_(enter_pin),
      max_name_length_(max_name_length) {
    // setup pins
    pinMode(left_, INPUT);
    pinMode(right_, INPUT);
    pinMode(select_, INPUT);
    pinMode(backspace_, INPUT);
    pinMode(enter_, INPUT);
}

int StartupGUI::run(char* file_name, int& name_length) {
    name_length = 0;
    
    // loop and take inputs
    bool left_pressed = false;
    bool right_pressed = false;
    bool select_pressed = false;
    bool backspace_pressed = false;

    do {
        if (checkSingleButtonPressed()) {
            // select button
            if (checkButtonStatus(select_)) {
                if(!select_pressed){
                    screen_.addData(screen_.data_[screen_.cursor_state_]);
                    file_name[name_length]= screen_.data_[screen_.cursor_state_];
                    name_length++;
                    select_pressed = true;
                }
            } else {
                select_pressed = false;
            }

            // backspace button
            if (checkButtonStatus(backspace_)) {
                if(!backspace_pressed){
                    screen_.deleteData();
                    name_length--;
                    backspace_pressed = true;
                }
            } else {
                backspace_pressed = false;
            }

            // left button
            if (checkButtonStatus(left_)) {
                if(!left_pressed){
                    screen_.cursorLeft();
                    left_pressed = true;
                }
            } else {
                left_pressed = false;
            }

            // right button
            if (checkButtonStatus(right_)) {
                if(!right_pressed){
                    screen_.cursorRight();
                    right_pressed = true;
                }
            } else {
                right_pressed = false;
            }
        }
        screen_.printScreen();
    } while (!checkButtonStatus(enter_));

    return 0;
}

bool StartupGUI::checkButtonStatus(int pin_number) {
    return digitalRead(pin_number);
}

bool StartupGUI::checkSingleButtonPressed() {
    return digitalRead(left_) ^ digitalRead(right_) ^ digitalRead(select_) ^
           digitalRead(backspace_) ^ digitalRead(enter_);
}
