//
//  robomodule_2515_CAN.h
//  
//
//  Created by lxh directed by clm.
//
//
//  INT------D2
//  SCK------D52
//  SI ------D51
//  SO-------D50
//  CS ------D53
//  GND -----GND
//  VCC------5V
#ifndef robomodule_2515_CAN_h
#define robomodule_2515_CAN_h
#include "SPI.h" 
#include "mcp2515.h"
#endif /* robomodule_2515_CAN_h */


class CRobomodule_2515_CAN
{
private:
	MCP2515 *mcp2515;
	
    int driver_group;
    int driver_number;
    int driver_mode;
    can_frame canMsg;
public:
	void setmode(int group,int number,int mode );
	void resetdriver(int group,int number );
    CRobomodule_2515_CAN();
    ~CRobomodule_2515_CAN();
    void initdriver(int baud,int group,int number,int mode);
    void speedwheel(int temp_pwm,int temp_velocity,int group,int number);
    void speedwheel(int temp_pwm,int group,int number);
};
