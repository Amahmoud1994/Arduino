#ifndef _ROS_beginner_tutorials_TelosBMsg_h
#define _ROS_beginner_tutorials_TelosBMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beginner_tutorials
{

  class TelosBMsg : public ros::Msg
  {
    public:
      int32_t sensorID;
      int32_t temperature;
      int32_t light;
      int32_t humidity;

    TelosBMsg():
      sensorID(0),
      temperature(0),
      light(0),
      humidity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_sensorID;
      u_sensorID.real = this->sensorID;
      *(outbuffer + offset + 0) = (u_sensorID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensorID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensorID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensorID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensorID);
      union {
        int32_t real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.real = this->light;
      *(outbuffer + offset + 0) = (u_light.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_light.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_light.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_light.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->light);
      union {
        int32_t real;
        uint32_t base;
      } u_humidity;
      u_humidity.real = this->humidity;
      *(outbuffer + offset + 0) = (u_humidity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humidity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humidity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humidity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->humidity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_sensorID;
      u_sensorID.base = 0;
      u_sensorID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensorID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensorID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensorID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sensorID = u_sensorID.real;
      offset += sizeof(this->sensorID);
      union {
        int32_t real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_light;
      u_light.base = 0;
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_light.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->light = u_light.real;
      offset += sizeof(this->light);
      union {
        int32_t real;
        uint32_t base;
      } u_humidity;
      u_humidity.base = 0;
      u_humidity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humidity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humidity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humidity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->humidity = u_humidity.real;
      offset += sizeof(this->humidity);
     return offset;
    }

    const char * getType(){ return "beginner_tutorials/TelosBMsg"; };
    const char * getMD5(){ return "348a93821ecd60205bfc9f54b86dd0a2"; };

  };

}
#endif