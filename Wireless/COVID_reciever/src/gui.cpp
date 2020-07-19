//---------------------------------------------//
// Reciever setup and GUI Functions
// Author: Thomas Kost
// Date: 6/30/20
//---------------------------------------------//
// This will contain all functions for carrying out the creation
// of data files for recording and performin all setup needs for 
// the DAQ box reciever (COVID)
#include<gui.h>


// initialize GUI
gui::gui(uint8_t A,
            uint8_t B,
            uint8_t up,
            uint8_t down,
            uint8_t left,
            uint8_t right)
{
    //save pin values
    m_A = A;
    m_B = B;
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;

    //initialize input pins
    pinmode(A, INPUT);
    pinmode(B, INPUT);
    pinmode(up, INPUT);
    pinmode(down, INPUT);
    pinmode(left, INPUT);
    pinmode(right, INPUT);
    
    //initialize OLED pins


}

//input handling
function gui::get_input()
{
    bool complete=false;
    while(!complete)
    {
        //read instructions
        input read_in=none;
        int A_val = digitalRead(m_A);
        int B_val = digitalRead(m_B);
        int up_val = digtalRead(m_up);
        int down_val = digitalRead(m_down);
        int left_val = digitalRead(m_left);
        int right_val = digitalRead(m_right);
        //select only one input
        if(A_val)
        {
            read_in=A;
            B_val=0;up_val=0;down_val=0;left_val=0;right_val=0;
        }
        else if(B_val)
        {
            read_in=A;
            up_val=0;down_val=0;left_val=0;right_val=0;
        }
        else if(up_val)
        {
            read_in=up;
            down_val=0;left_val=0;right_val=0;
        }
        else if(down_val)
        {
            read_in=down;
            left_val=0;right_val=0;
        }
        else if(left_val)
        {
            read_in=left;
            right_val=0;
        }
        else if(right_val)
        {
            read_in=right;
        }

        //check function and do behaviour associated with that function
        
    }
    return 0;
}
// file setup
string gui::get_file_name()
{

}
void gui::init_file()
{

}
