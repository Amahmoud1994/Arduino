#ifndef _ROS_mongodb_store_msgs_MoveEntriesFeedback_h
#define _ROS_mongodb_store_msgs_MoveEntriesFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store_msgs
{

  class MoveEntriesFeedback : public ros::Msg
  {
    public:
      uint8_t completed_length;
      char* st_completed;
      char* * completed;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = completed_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < completed_length; i++){
      uint32_t length_completedi = strlen( (const char*) this->completed[i]);
      memcpy(outbuffer + offset, &length_completedi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->completed[i], length_completedi);
      offset += length_completedi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t completed_lengthT = *(inbuffer + offset++);
      if(completed_lengthT > completed_length)
        this->completed = (char**)realloc(this->completed, completed_lengthT * sizeof(char*));
      offset += 3;
      completed_length = completed_lengthT;
      for( uint8_t i = 0; i < completed_length; i++){
      uint32_t length_st_completed;
      memcpy(&length_st_completed, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_completed; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_completed-1]=0;
      this->st_completed = (char *)(inbuffer + offset-1);
      offset += length_st_completed;
        memcpy( &(this->completed[i]), &(this->st_completed), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "mongodb_store_msgs/MoveEntriesFeedback"; };
    const char * getMD5(){ return "a62bad29223cd7da9d6f04397aee5b94"; };

  };

}
#endif