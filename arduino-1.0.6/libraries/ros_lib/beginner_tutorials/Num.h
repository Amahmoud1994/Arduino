#ifndef _ROS_beginner_tutorials_Num_h
#define _ROS_beginner_tutorials_Num_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beginner_tutorials
{

  class Num : public ros::Msg
  {
    public:
      const char* first_name;
      const char* last_name;
      uint8_t age;
      uint32_t score;

    Num():
      first_name(""),
      last_name(""),
      age(0),
      score(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_first_name = strlen(this->first_name);
      memcpy(outbuffer + offset, &length_first_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->first_name, length_first_name);
      offset += length_first_name;
      uint32_t length_last_name = strlen(this->last_name);
      memcpy(outbuffer + offset, &length_last_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->last_name, length_last_name);
      offset += length_last_name;
      *(outbuffer + offset + 0) = (this->age >> (8 * 0)) & 0xFF;
      offset += sizeof(this->age);
      *(outbuffer + offset + 0) = (this->score >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->score >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->score >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->score >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_first_name;
      memcpy(&length_first_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_first_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_first_name-1]=0;
      this->first_name = (char *)(inbuffer + offset-1);
      offset += length_first_name;
      uint32_t length_last_name;
      memcpy(&length_last_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_last_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_last_name-1]=0;
      this->last_name = (char *)(inbuffer + offset-1);
      offset += length_last_name;
      this->age =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->age);
      this->score =  ((uint32_t) (*(inbuffer + offset)));
      this->score |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->score |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->score |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->score);
     return offset;
    }

    const char * getType(){ return "beginner_tutorials/Num"; };
    const char * getMD5(){ return "f8bfa80ae3c7a93455596d9622ad33a9"; };

  };

}
#endif