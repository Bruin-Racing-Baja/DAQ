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

## ECVT Temperature Sensor - SPICY

Fault detection and prevention is a priority in Model 21. As failure due to overheating has been a known issue with ECVT performance, we aim to be able to measure and provide warnings in advance for possible temperature related failures. Our Sudden PressfIt Calamity detection sYstem makes use of a DS18B20 1-wire protocol thermometer. This small IC is capable of reading temperatures up to 125 degrees celcius, making it capable of reading the temperatures at which we suspect the pressfit to fail. This sensor system will be coupled with a greater effort to foster cooling of the ECVT, including but not limited to active cooling and passive cooling through cover design.

# Dictionary

Naming things is half the fun of it, a comprehensive list will be here.

- COVID - Communicating Onboard Vehicle Information Device
- BUTT - Better Underside Teensy Terminal : Teensy 4.0 Hardware Adaptor (DEAD)
- DAQ - Data Acquistion
- SPICY - Sudden PressfIt Calamity detection sYstem

