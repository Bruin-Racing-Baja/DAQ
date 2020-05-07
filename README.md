# DAQ
Data aquisition code and transmission code for Baja Bruin Racing electronics. 

- [Model 21 Systems](#model-21-systems)
- [Dictionary](#dictionary)

Testing systems and their associated code will be each broken down in the DAQ repository.

All scripts will be organized three main folders:
- `Wireless` contains code relevant to all wireless communications for the Bruin Racing, this will include but is not limited to LoRa, WiFi, and various RF modules.
- `Testing` contains the code relevant to each particular test. This will contain scripts and data for all tests ran during the 2021 design cycle.
- `Libraries` contains all developed libraries for sensor use. This directory is broken down by each type of sensor, containing the library of functions used to operate each sensor.


# Model 21 Systems

## DAQ Long Range Transmitter/Reciever - COVID

Model 21 aims to better enhance the data aquisition capabilities with our Communicating Onboard Vehicle Infomation Device (COVID). This is a teensy based data aquisition device, using LoRa protocol at the 915Mhz bandwidth to both record data locally and transmit it to a handheld reciever. The transmitter reciever pair are designed to be flexible to work with a variaty of sensors, and provide high data rates for sufficent sampling. 

# Dictionary

Naming things is half the fun of it, a comprehensive list will be here.

- COVID - Communicating Onboard Vehicle Information Device
- BUTT - Better Underside Teensy Terminal : Teensy 4.0 Hardware Adaptor
- DAQ - Data Acquistion

