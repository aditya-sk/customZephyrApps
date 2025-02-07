/*
 * Author: Aditya SanthaKulluru
 */

// std and zephyr headers
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>





/* 1000 msec = 1 sec */
#define SLEEP_TIME_MSZ   500

/* Devicetree node identifier for the "led0"and "led1" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

/*
 * 
 * 
 */
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
int main(void)
{
	int ret0, ret1;
	bool led_state0 = true;
	bool led_state1 = true;
	if (!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&led1)) 
	{
		return 0;
	}

	ret0 = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
	ret1 = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
	if (ret0 < 0 || ret1 <0) 
	{
		return 0;
	}
	printf("The state of LED is displayed every millisecond.\r\n");

	while (1) 
	{

		// //Toggle Led0
		gpio_pin_toggle_dt(&led0);
		led_state0 = !led_state0;
		printf("LED Zero state : %s\n", led_state0 ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MSZ);
		// Toggle led0 and led1
		gpio_pin_toggle_dt(&led1);
		led_state1 = !led_state1;
		printf("\tLED One state : %s\n", led_state1 ? "ON" : "OFF");
		gpio_pin_toggle_dt(&led0);
		led_state0 = !led_state0;
		printf("\tLED Zero state : %s\n", led_state0 ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MSZ);
	}
		return 0;
}
