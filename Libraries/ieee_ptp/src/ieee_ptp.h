//---------------------------------------------//
// IEEE Precise Time Protocol Library
// Author: Thomas Kost
// Date: 6/2/20
//---------------------------------------------//
// Description:
// This library is designed for implementation
// on Teensy and Arduino like architectures. 
// This is used to make local networks of 
// several microcontrollers with a sense of 
// time synched between several microcontrollers
// all linked to a single master pin
//---------------------------------------------//
#include <TimerOne.h>



//will require serial
typedef char uint8_t, int uint16_t ;
//each port will require 4 connections plus ground (but everything should be common grounded)
struct ptp_port
{
    ptp_port(uint8_t tx, uint8_t rx, uint8_t ms, uint8_t ss): m_tx(tx), m_rx(rx), m_master_signal(ms), m_slave_signal(ss){};
    uint8_t m_tx;
    uint8_t m_rx;
    uint8_t m_master_signal;
    uint8_t m_slave_signal;
};

class ptp
{
    //could possibly make this a singleton class, but fine for now
    public:
    ptp(bool master, uint16_t f=10, uint16_t microseconds=100):m_master(master), m_freq(f), m_ms(microseconds), num_ports(0)
    {
        if(m_master)
    {
        //make function trigger on timer
        uint16_t mSec = (uint16_t)1e6/f;
        Timer1.initalizae(mSec);
        Timer1.attatchInterrupt(synchronize_m);
    }
    else
    {
        ;
    }
    }
    int attatch_ptp_port(uint8_t tx_pin, uint8_t rx_pin,uint8_t m_out, uint8_t s_out);
    void set_frequency(uint16_t f);// default 10hZ (should be the max)
    void set_precision(uint16_t microseconds);
    void detatch_ptp();

    private:
    void update_timer(); //interrupt attached functions
    void synchronize_s(); //flip pin
    void synchronize_m(); //flip pin
    ptp_port ports[8];
    uint8_t num_ports;
    uint8_t m_freq;
    uint16_t m_ms;
    bool m_master;

    const int ptp_baud = 115200;

};