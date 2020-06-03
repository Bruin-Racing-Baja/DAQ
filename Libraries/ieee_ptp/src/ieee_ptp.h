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

//will require serial
typedef char uint8_t, int uint32_t ;

class ptp
{
    public:
    void init_ptp(uint8_t,  bool);
    ptp(uint8_t pin, bool master, uint32_t f=10, uint32_t microseconds=100):freq(f), ms(microseconds){
        init_ptp(pin, master);
    };
    void attatch_ptp(uint8_t tx_pin, uint8_t rx_pin);
    void set_frequency(uint32_t f);// default 10hZ (should be the max)
    void set_precision(uint32_t microseconds);
    void detatch_ptp();

    private:
    void init_ptp(uint8_t pin, bool master);
    void update_timer(); //interrupt attached functions
    void synchronize(); //flip pin
    uint8_t freq;
    uint8_t ms;
    bool master;
};