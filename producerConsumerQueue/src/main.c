/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include "producer.h"
#include "consumer.h"

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
/* 
 * Zephyr Thread defines for Producer and Consumer stack allocation. 
*/ 
#define STACKSIZE 1024 
#define PRIORITY 7 
K_THREAD_STACK_DEFINE(producerThreadstack_area, STACKSIZE); 
struct k_thread producerThread_data; 
K_THREAD_STACK_DEFINE(consumerThreadstack_area, STACKSIZE); 
struct k_thread consumerThread_data; 
/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	printf("We are using Threads. Producer and Consumer Threads now.\r\n");

	k_tid_t producer_tid = k_thread_create(&producerThread_data, producerThreadstack_area, K_THREAD_STACK_SIZEOF(producerThreadstack_area), producerThread, (void*)&led, (void*)NULL, (void*)NULL, PRIORITY, 0, K_NO_WAIT);

	k_tid_t consumer_tid = k_thread_create(&consumerThread_data, consumerThreadstack_area, K_THREAD_STACK_SIZEOF(consumerThreadstack_area), consumerThread,	(void*)NULL, (void*)NULL, (void*)NULL, PRIORITY, 0, K_NO_WAIT);		
	
	
	while (1) {
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
