#ifndef _ROS_nav2d_operator_cmd_h
#define _ROS_nav2d_operator_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nav2d_operator
{

  class cmd : public ros::Msg
  {
    public:
      float Velocity;
      float Turn;
      int8_t Mode;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_Velocity = (int32_t *) &(this->Velocity);
      int32_t exp_Velocity = (((*val_Velocity)>>23)&255);
      if(exp_Velocity != 0)
        exp_Velocity += 1023-127;
      int32_t sig_Velocity = *val_Velocity;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Velocity<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Velocity>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Velocity>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Velocity<<4) & 0xF0) | ((sig_Velocity>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Velocity>>4) & 0x7F;
      if(this->Velocity < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_Turn = (int32_t *) &(this->Turn);
      int32_t exp_Turn = (((*val_Turn)>>23)&255);
      if(exp_Turn != 0)
        exp_Turn += 1023-127;
      int32_t sig_Turn = *val_Turn;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Turn<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Turn>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Turn>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Turn<<4) & 0xF0) | ((sig_Turn>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Turn>>4) & 0x7F;
      if(this->Turn < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int8_t real;
        uint8_t base;
      } u_Mode;
      u_Mode.real = this->Mode;
      *(outbuffer + offset + 0) = (u_Mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_Velocity = (uint32_t*) &(this->Velocity);
      offset += 3;
      *val_Velocity = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Velocity |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Velocity = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Velocity |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Velocity !=0)
        *val_Velocity |= ((exp_Velocity)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Velocity = -this->Velocity;
      uint32_t * val_Turn = (uint32_t*) &(this->Turn);
      offset += 3;
      *val_Turn = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Turn |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Turn |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Turn |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Turn = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Turn |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Turn !=0)
        *val_Turn |= ((exp_Turn)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Turn = -this->Turn;
      union {
        int8_t real;
        uint8_t base;
      } u_Mode;
      u_Mode.base = 0;
      u_Mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Mode = u_Mode.real;
      offset += sizeof(this->Mode);
     return offset;
    }

    const char * getType(){ return "nav2d_operator/cmd"; };
    const char * getMD5(){ return "90c9a043660646e2102f124332ecb8b7"; };

  };

}
#endif