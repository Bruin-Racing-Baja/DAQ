//---------------------------------------------//
// Reciever setup and GUI Functions
// Author: Thomas Kost
// Date: 6/30/20
//---------------------------------------------//
// This will contain all functions for carrying out the creation
// of data files for recording and performin all setup needs for 
// the DAQ box reciever (COVID)
#include <..\types\types.h>
#include <Arduino.h>

enum function;
enum state;
class gui
{
    public:
    gui(uint8_t A,
            uint8_t B,
            uint8_t up,
            uint8_t down,
            uint8_t left,
            uint8_t right);
    function get_input();
    string get_file_name();
    void init_file();
    private:
    uint8_t m_A;
    uint8_t m_B;
    uint8_t m_up;
    uint8_t m_down;
    uint8_t m_left;
    uint8_t m_right;
    String  m_file_Name;
    state m_state;
}


//enum for ease and clarity
enum input 
{
    //GBA style d pad setup
    up =0,
    left=1,
    right=2,
    down=3,
    select=4, //A
    back=5,   //B
    none=6
};

enum function
{
    create_file =0,
    start_test=1,
    end_test=2,
    none=3
};
enum state
{
    start_screen=0,
    ready_screen=1,
    display_data=2,
    exit_screen=3,
    keyboard=4
};