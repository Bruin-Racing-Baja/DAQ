//---------------------------------------------//
// IEEE Precise Time Protocol Library
// Author: Thomas Kost
// Date: 6/2/20
//---------------------------------------------//
#include <TimerOne.h>
#include <digitalWriteFast.h>
#include <ieee_ptp.h>

int ptp::attatch_ptp_port(uint8_t tx_pin, uint8_t rx_pin, uint8_t m_out,
                          uint8_t s_out) {
    // establishes serial connection
    ptp_port p(tx_pin, rx_pin, m_out, s_out);
    if ((num_ports < 8 && m_master) || (num_ports == 0 && !m_master)) {
        // master can have up to 8 ports, slave can have only 1 port
        ports[num_ports] = p;
        num_ports++;
    } else {
        return -1;
    }

    if (m_master) {
        pinmode(m_out, OUTPUT);
        pinmode(s_out, INPUT);
        switch (num_ports) {
            case 0:
                Serial1.setTX(tx_pin);
                Serial1.setRx(rx_pin);
                Serial1.begin(ptp_baud);
                break;
            case 1:
                Serial2.setTX(tx_pin);
                Serial2.setRx(rx_pin);
                Serial2.begin(ptp_baud);
                break;
            case 2:
                Serial3.setTX(tx_pin);
                Serial3.setRx(rx_pin);
                Serial3.begin(ptp_baud);
                break;
            case 3:
                Serial4.setTX(tx_pin);
                Serial4.setRx(rx_pin);
                Serial4.begin(ptp_baud);
                break;
            case 4:
                Serial5.setTX(tx_pin);
                Serial5.setRx(rx_pin);
                Serial5.begin(ptp_baud);
                break;
            case 5:
                Serial6.setTX(tx_pin);
                Serial6.setRx(rx_pin);
                Serial6.begin(ptp_baud);
                break;
            case 6:
                Serial7.setTX(tx_pin);
                Serial7.setRx(rx_pin);
                Serial7.begin(ptp_baud);
                break;
            case 7:
                Serial8.setTX(tx_pin);
                Serial8.setRx(rx_pin);
                Serial8.begin(ptp_baud);
                break;
            default:
                return -1;
        }
    }

    else {
        // setup slave
        attatchInterrupt(digitalPinToInterrupt(m_out), synchronize_s);
    }

    return 0;
}

void ptp::set_frequency(uint16_t f)  // default 10hZ (should be the max)
{
    // sets frequncy, will not allow to go higher than 10, per protocol
    // regulations
    m_freq = std::min(f, 10);
    return;
}

void ptp::set_precision(uint16_t microseconds) {
    //  sets tolerance for error
    m_ms = microseconds;
    return;
}

void ptp::detatch_ptp() {
    // Master: Stops all synchronyzation
    // Slave: allows slave to run ansychronously from master
    if (!m_master) {
        detatchInterrupt(digitalPinToInterrupt(m_i_pin));
    } else {
        // terminate timer for master
        Timer1.detatchInterrrupt();
    }

    return;
}
void ptp::synchronize_s() { return; }
void ptp::synchronize_m() {
    nointerrupt();
    uint16_t current_time = TCNT1;
    digitalWriteFast(m_i_pin, HIGH);  // tell other micrcocontrollers its time
                                      // to execute synchronization
    // recieve serial data

    return;
}