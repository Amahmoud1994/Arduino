#ifndef _ROS_mongodb_store_msgs_MoveEntriesAction_h
#define _ROS_mongodb_store_msgs_MoveEntriesAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mongodb_store_msgs/MoveEntriesActionGoal.h"
#include "mongodb_store_msgs/MoveEntriesActionResult.h"
#include "mongodb_store_msgs/MoveEntriesActionFeedback.h"

namespace mongodb_store_msgs
{

  class MoveEntriesAction : public ros::Msg
  {
    public:
      mongodb_store_msgs::MoveEntriesActionGoal action_goal;
      mongodb_store_msgs::MoveEntriesActionResult action_result;
      mongodb_store_msgs::MoveEntriesActionFeedback action_feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mongodb_store_msgs/MoveEntriesAction"; };
    const char * getMD5(){ return "f7d864f6b635e826539248bb692f31e4"; };

  };

}
#endif