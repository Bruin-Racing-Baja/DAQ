# IEEE Precice Time Protocol Library

This library is for the use of creating a local network between several micontrollers in synchronous time. This is implemented through a master slave type architecture and is designed to allow for multiple microcontrollers simultaneously reading several sensors with aligned time stamps. This library is designed to be teensy friendly and initially implemented on the Teensy 4.1.

## API

General implementation of this library is a class containing all the functionality of the syncronyzer. The class is to be instantiated in both the master and slave devices, with the appropriate interrupt and serial communication pins. An overview of the functions can be seen below:

|  Function | Description  |
|:---------:|:------------:|
| constructor | Initializes the ptp object as either a master or a slave with the appropriate serial and |interrupt pins |
|  ptp_attatch | For master adds serial port, for slave adds serial port and interrupt pin functionality|
|   set_frequency| changes how often the synchronization is done, default is the max value of 10 Hz   |
| set_precision|  Sets maximum number of microseconds allowable for count to be off without timer adjustment. Default is 100 microseconds|
