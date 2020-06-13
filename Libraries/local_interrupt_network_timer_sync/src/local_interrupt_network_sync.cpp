//---------------------------------------------//
// Synchronized Time Reset Library
// Author: Thomas Kost
// Date: 6/8/2020
//---------------------------------------------//

#include <local_interrupt_network_sync.h>
#include <TimerOne.h>
#include <digitalWriteFast.h>


//public functions
LINTS:: LINTS(uint8_t pin, bool master, uint16_t period )
{
    m_int_pin = pin;
    m_master  = master;
    m_recordings = new uint16_t [16]; //might not need to be dynamically allocated
    m_length = 0;
    m_period = period;
    m_state = 0;
}
LINTS::~LINTS()
{
    delete [] m_recordings;
}

void LINTS::begin()
{
    if(m_master)
    {
        // if master set up timer and interrupt to throw connected pin high
        Timer1.initialize(m_period);
        Timer1.attatchInterrupt(m_record);
    }
    else
    {
        //if slave, set up interrupt on pin to call record function and start timer 
        pinMode(m_int_pin, INPUT);
        attatchInterrupt(digitalPinToInterrupt(m_int_pin), s_record, CHANGE);
    }
    
    return;
}

uint16_t* LINTS::get_offsets(uint16_t& len)
{
    len = m_length;
    m_length = 0;
    return m_recordings;
}

//private, internals

void LINTS::s_record()
{
    m_recordings[m_length] = TCNT1;
    m_length++;
    return;
}
void LINTS::m_record()
{
    m_recordings[m_length] = TCNT1;
    m_state = !m_state;
    digitalWriteFast(m_int_pin, m_state);
    m_length++; //do at end so ,minimize time between storing time and starting
    return;
}