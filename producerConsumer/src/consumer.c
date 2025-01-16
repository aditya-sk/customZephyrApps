#include <zephyr/kernel.h>
#include "consumer.h"

void consumerThread(void*, void*, void*)
{
    uint32_t data = 0;
    while(1)
    {
        k_msleep(SLEEP_TIME_MS);
        printf("Consumer Thread: %d\r\n", data);
        data++;
    }
}