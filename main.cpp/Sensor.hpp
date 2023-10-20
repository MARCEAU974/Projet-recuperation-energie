#ifndef _SEEED_HM330X_H
#define _SEEED_HM330X_H

#include "Arduino.h"
#include "HM330XErrorCodes.hpp"
#include "I2COperation.hpp"


#define DEFAULT_IIC_ADDR  0x40
#define SELECT_COMM_CMD   0X88


class HM330X : public I2COperation {
  public:
    HM330X(uint8_t IIC_ADDR = DEFAULT_IIC_ADDR);

    HM330XErrorCodes init();

    HM330XErrorCodes read_sensor_value(uint8_t* data, uint32_t data_len);
     
  private:
    HM330XErrorCodes select_comm();
};


#endif