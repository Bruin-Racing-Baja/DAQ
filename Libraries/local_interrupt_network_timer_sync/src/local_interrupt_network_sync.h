//---------------------------------------------//
// Synchronized Time Reset Library
// Author: Thomas Kost
// Date: 6/8/2020
//---------------------------------------------//
// This library is designed to be a lightweight
// library for the use of synchronyzing data in
// recorded in post processing. 
//---------------------------------------------//

typedef char uint8_t, unsigned int uint16_t;

//note on usage: get_offsets must be called before every 16*period/1000000 S to prevent a loss of data
class LINTS
{
    public:
    LINTS(uint8_t pin, bool master, uint16_t period);
    ~LINTS();
    void begin();
    uint16_t* get_offsets(uint16_t& len);

    private:
    // data members
    uint8_t m_int_pin;
    bool m_master;
    uint16_t* m_recordings;
    uint16_t m_length;
    uint16_t m_period;
    volatile uint8_t m_state;
    //member functions
    void s_record();
    void m_record();
};