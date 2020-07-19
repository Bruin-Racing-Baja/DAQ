//---------------------------------------------//
// C.O.V.I.D. Transmitter                      //
// Author: Thomas Kost                         //
// Last Updated: 5/4/20                        //
// Description: LoRa Based transmitter for DAQ //
//---------------------------------------------//

#include <Arduino.h>
#include <LoRa.h>

// Constants
const uint32_t us_std_freq = 915E6;

// Pins
const uint8_t ss = 10;
const int8_t reset = -1;  // tie to uC reset
const uint8_t dio0 = 2;   // requires interrupt capable pin

// global variables
uint32_t timer = 0

    // prototypes
    void
    onTxDone();

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    LoRa.begin(us_std_freq);
    LoRa.setPins(ss, reset, dio0);
    LoRa.onTxDone(onTxDone);
}

void loop() {
    // put your main code here, to run repeatedly:
    // Generate test number
    timer = millis();
    Serial.println(timer);

    // Send data to the reciever (safely)
    while (Lora.beginPacket()) {
        Serial.println('Not Ready to Transmit\n');
        delay(100);
    }
    LoRa.write(timer, length(typeof(timer)));
    LoRa.endPacket();
}
void onTxDone() {
    Serial.println('Message Completed. Sent %i', timer);
    float snr = LoRa.packetSnr();
    Serial.println('Estimated SNR: %f', snr);
}