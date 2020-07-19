/**
 *  File: screen.cpp
 *
 *  Author: Thomas Kost
 *
 *  Date: 07 August 2020
 *
 *  @brief contains screen object and state of the OLED SCREEN for COVID
 * Reciever
 *
 */
#include <screen.h>

OLED_Screen::OLED_Screen()
    : cursor_state_(0),
      data_("ABCDEFGHIJKLMNOPQRSTUVWXYZ_:"),
      screen_data_length_(28),
      intitial_screen_data_length_(27),
      display_(128, 32, &SPI, OLED_DC, OLED_RESET, OLED_CS)
       {
    if (!display_.begin(0x3C)) {
        Serial.println("Unable to initialize OLED");
        while (1) yield();
    }
    display_.display();
    delay(2000);  // feels a little more calm
    display_.clearDisplay();
    delay(1000);
    display_.setTextSize(1);
    display_.setTextWrap(false);
    display_.setTextColor(WHITE);
    display_.setCursor(7, 0);
}

void OLED_Screen::printScreen() {
    display_.clearDisplay();
    display_.setCursor(7, 0);

    for (int i = 0; i < screen_data_length_; i++) {
        if (i == cursor_state_) display_.setTextColor(BLACK, WHITE);
        display_.write(data_[i]);
        if ((i > 0) && (i % 19 == 0)) {
            display_.println();
            display_.write(' ');
        }
        if (i == cursor_state_) {
            display_.setTextColor(WHITE);
        }
    }
    display_.display();
    return;
}

void OLED_Screen::addData(char new_character) {
    if (screen_data_length_ >= OLED_SCREEN_HEIGHT * OLED_SCREEN_WIDTH) {
        return;
    }
    data_[screen_data_length_] = new_character;
    screen_data_length_++;
    return;
}

void OLED_Screen::deleteData() {
    if (screen_data_length_ <= intitial_screen_data_length_) return;
    screen_data_length_--;
    return;
}

void OLED_Screen::cursorLeft() {
    if (cursor_state_ > 0) {
        cursor_state_--;
    }
    return;
}

void OLED_Screen::cursorRight() {
    if (cursor_state_ < intitial_screen_data_length_) {
        cursor_state_++;
    }
    return;
}

char OLED_Screen::cursorSelect() { return data_[cursor_state_]; }