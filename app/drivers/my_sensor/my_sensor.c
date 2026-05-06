#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

#define DT_DRV_COMPAT my_sensor

// Register the driver with the logging 
LOG_MODULE_REGISTER(my_sensor, LOG_LEVEL_INF);


// Configure LED 
#define LED_NODE DT_ALIAS(app_led)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);


static int my_sensor_channel_get(const struct device *dev,
								 enum sensor_channel chan,
			    				struct sensor_value *val)
	{
		LOG_INF("Hello from my Sensor channel get function \n");

     	gpio_pin_set_dt(&led, 0);
		LOG_INF("LED state: OFF");

			return 0;
	}

static int my_sensor_sample_fetch(  const struct device *dev, 
									enum sensor_channel chan)
	{
		LOG_INF("Hello from my Sensor sample fetch function \n");

     	gpio_pin_set_dt(&led, 1); 
		LOG_INF("LED state: ON");
		
			return 0;
	}



static DEVICE_API(sensor, my_sensor_api) = {
	.channel_get = my_sensor_channel_get,
	.sample_fetch = my_sensor_sample_fetch,
} ;

// Init function 

static int init(const struct device *dev){
    
	// Make sure that the LED was initialized
	if (!gpio_is_ready_dt(&led)) return 0;
	if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) return 0;
	
	LOG_INF("Hello from my_sensor init function \n");

    return 0;
}

DEVICE_DT_INST_DEFINE(0, init, NULL, NULL, NULL, POST_KERNEL, 80, &my_sensor_api);