#include <zephyr/kernel.h> 

#include <zephyr/drivers/gpio.h> 

#include "producer.h" 

 

void producerThread(void *inLed, void*, void*) { 

    struct gpio_dt_spec *toggleLED = (struct gpio_dt_spec*)inLed; 

    bool led_state = true; 
    int counter = 0; 
    uint32_t data = 0; 

    while (1) { 

    gpio_pin_toggle_dt(toggleLED); 
    led_state = !led_state; 

    printf("LED state: %s\n", led_state ? "ON" : "OFF"); 

    k_msleep(SLEEP_TIME_MS); 

    }
}