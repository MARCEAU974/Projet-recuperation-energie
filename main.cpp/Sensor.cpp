#include "Sensor.hpp"

HM330X::HM330X(uint8_t IIC_ADDR) {
    set_iic_addr(IIC_ADDR);
}

HM330XErrorCodes HM330X::select_comm() {
    return IIC_SEND_CMD(SELECT_COMM_CMD);
}

HM330XErrorCodes HM330X::init() {
    Wire.begin();
    return select_comm();
}

HM330XErrorCodes HM330X::read_sensor_value(uint8_t* data, uint32_t data_len) {
    uint32_t time_out_count = 0;
    HM330XErrorCodes ret = NO_ERROR;
    Wire.requestFrom(0x40, 29);
    while (data_len != Wire.available()) {
        time_out_count++;
        if (time_out_count > 10) {
            return ERROR_COMM;
        }
        delay(1);
    }
    for (int i = 0; i < data_len; i++) {
        data[i] = Wire.read();
    }
    return ret;
}