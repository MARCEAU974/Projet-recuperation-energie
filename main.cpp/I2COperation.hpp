#ifndef SEEED_PM2_5_SENSOR_HM3301_I2C_OPERATIONS_H
#define SEEED_PM2_5_SENSOR_HM3301_I2C_OPERATIONS_H

#include "Arduino.h"
#include "Wire.h"
#include "HM330XErrorCodes.hpp"

class I2COperation {
  public:

    HM330XErrorCodes IIC_write_byte(uint8_t reg, uint8_t byte);

    HM330XErrorCodes IIC_read_byte(uint8_t reg, uint8_t* byte);

    void set_iic_addr(uint8_t IIC_ADDR);

    HM330XErrorCodes IIC_read_16bit(uint8_t start_reg, uint16_t* value);

    HM330XErrorCodes IIC_write_16bit(uint8_t reg, uint16_t value);

    HM330XErrorCodes IIC_read_bytes(uint8_t start_reg, uint8_t* data, uint32_t data_len);

    HM330XErrorCodes IIC_SEND_CMD(uint8_t CMD);

  private:
    uint8_t _IIC_ADDR;
};


#endif //SEEED_PM2_5_SENSOR_HM3301_I2C_OPERATIONS_H
