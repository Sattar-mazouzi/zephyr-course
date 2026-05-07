#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>
#include "my_sensor.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

#define SLEEP_TIME_MS 1000




const struct device* driver = DEVICE_DT_GET(DT_NODELABEL(my_sensor0));
struct sensor_value val;



int main(void)
{
    my_sensor_set_brightness(driver, 42);   // Change internal parameter
    while (1) {

        // Turn on LED
        auto sample_ret = sensor_sample_fetch(driver);
        k_msleep(SLEEP_TIME_MS);
        // Turn off LED
        auto cha_ret = sensor_channel_get(driver, SENSOR_CHAN_AMBIENT_TEMP, &val);
        k_msleep(SLEEP_TIME_MS);

    }
    return 0;
}
