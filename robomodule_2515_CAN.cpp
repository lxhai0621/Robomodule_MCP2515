//
//  robomodule_2515_CAN.cpp
//  
//
//  Created by lxh directed by clm.
//
//

#include "robomodule_2515_CAN.h"
CRobomodule_2515_CAN::CRobomodule_2515_CAN()
{
	mcp2515=new MCP2515(53);
    driver_group=0;
    driver_number=0;
    driver_mode=3;
}
void CRobomodule_2515_CAN::resetdriver(int group=0,int number=0)
{
    canMsg.can_id=((uint32_t)group)<<8|(uint32_t)((number<<4)&0xf0);
    canMsg.can_dlc=8;
    canMsg.data[0]=0x55;
    canMsg.data[1]=0x55;
    canMsg.data[2]=0x55;
    canMsg.data[3]=0x55;
    canMsg.data[4]=0x55;
    canMsg.data[5]=0x55;
    canMsg.data[6]=0x55;
    canMsg.data[7]=0x55;
    mcp2515->sendMessage(&canMsg);
    delay(500);
}
void CRobomodule_2515_CAN::setmode(int group=0,int number=0,int mode=3 )
{
    canMsg.can_id=((uint32_t)group)<<8|(uint32_t)(((number<<4)|0x01)&0xf1);
    canMsg.can_dlc=8;
    canMsg.data[0]=mode;
    canMsg.data[1]=0x55;
    canMsg.data[2]=0x55;
    canMsg.data[3]=0x55;
    canMsg.data[4]=0x55;
    canMsg.data[5]=0x55;
    canMsg.data[6]=0x55;
    canMsg.data[7]=0x55;
    mcp2515->sendMessage(&canMsg);
    delay(500);
}

void CRobomodule_2515_CAN::speedwheel(int temp_pwm,int temp_velocity,int group=0,int number=0)
{
    canMsg.can_id=((uint32_t)group)<<8|(uint32_t)(((number<<4)|0x04)&0xf4);
    canMsg.can_dlc=8;
    canMsg.data[0]=( char)((temp_pwm>>8)&0xff);
    canMsg.data[1]=( char)(temp_pwm & 0xff);
    canMsg.data[2]=( char)((temp_velocity>>8) & 0xff);
    canMsg.data[3]=( char)(temp_velocity & 0xff);
    canMsg.data[4]=0x55;
    canMsg.data[5]=0x55;
    canMsg.data[6]=0x55;
    canMsg.data[7]=0x55;
    mcp2515->sendMessage(&canMsg);
    delay(5);
}
void CRobomodule_2515_CAN::speedwheel(int temp_pwm,int group=0,int number=0)
{
    canMsg.can_id=((uint32_t)group)<<8|(uint32_t)(((number<<4)|0x02)&0xf2);
    canMsg.can_dlc=8;
    canMsg.data[0]=( char)((temp_pwm>>8)&0xff);
    canMsg.data[1]= ( char)(temp_pwm & 0xff);
    canMsg.data[2]=0x55;
    canMsg.data[3]=0x55;
    canMsg.data[4]=0x55;
    canMsg.data[5]=0x55;
    canMsg.data[6]=0x55;
    canMsg.data[7]=0x55;
    mcp2515->sendMessage(&canMsg);
    delay(5);
}
void CRobomodule_2515_CAN::initdriver(int baud=CAN_1000KBPS,int group=0,int number=0,int mode=3)
{
	mcp2515->reset();
	mcp2515->setBitrate(baud,MCP_8MHZ);
	mcp2515->setNormalMode();
    resetdriver(group,number);
    setmode(group,number,mode);
    
}
CRobomodule_2515_CAN::~CRobomodule_2515_CAN()
{
	delete mcp2515;
}

