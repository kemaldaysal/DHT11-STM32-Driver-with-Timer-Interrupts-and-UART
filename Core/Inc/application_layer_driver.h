/*
 * application_layer_driver.h
 *
 *  Created on: May 12, 2024
 *      Author: Kemal
 */

#ifndef INC_APPLICATION_LAYER_DRIVER_H_
#define INC_APPLICATION_LAYER_DRIVER_H_

#include "timer_driver.h"
#include "dht11_driver.h"
#include "uart_driver.h"

void start_dht11_timer_and_uart(uint16_t dht11_measurement_period_in_milliseconds, uint32_t uart_baudrate);

#endif /* INC_APPLICATION_LAYER_DRIVER_H_ */
