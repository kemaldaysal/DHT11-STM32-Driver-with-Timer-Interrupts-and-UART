/*
 * application_layer_driver.c
 *
 *  Created on: May 12, 2024
 *      Author: Kemal
 */

#include "application_layer_driver.h"

void start_dht11_timer_and_uart(uint16_t dht11_measurement_period_in_milliseconds, uint32_t uart_baudrate)
{
	  UART_init(uart_baudrate);
	  dht11_and_timer_start(dht11_measurement_period_in_milliseconds);
}
