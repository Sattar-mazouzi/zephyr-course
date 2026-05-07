#ifndef ZEPHYR_DRIVERS_MY_SENSOR_H_
#define ZEPHYR_DRIVERS_MY_SENSOR_H_

#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

void my_sensor_set_brightness(const struct device *dev, int value);

#ifdef __cplusplus
}
#endif

#endif /* MY_SENSOR_H */
