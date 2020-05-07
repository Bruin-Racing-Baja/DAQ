//---------------------------------------------//
// C.O.V.I.D. Reciever                         //
// Author: Thomas Kost                         //
// Last Updated: 5/4/20                        //
// Description: LoRa Based reciever for DAQ    //
//---------------------------------------------//

#include <Arduino.h>
#include <LoRa.h>

//Constants
int us_std_freq = 915E6;

int ss = 10;
int reset =-1;      //tie to uC reset
int dio0 =2;        //requires interrupt capable pin
//void onRecieve ();
void setup() {
  // put your setup code here, to run once:
  LoRa.begin(us_std_freq);
  LoRa.setPins(ss, reset, dio0);
  //Lora.onRecieve(onRecieve)
  LoRa.recieve();
}
void loop() {
  // put your main code here, to run repeatedly:
  char buffer [10];
  char b = 0;
  uint8_t index=0;
  while(b != -1)
    { 
      b = LoRa.read()
      buffer[index] = b;
      index++;
    }
  //concatenate the bits read
  

}