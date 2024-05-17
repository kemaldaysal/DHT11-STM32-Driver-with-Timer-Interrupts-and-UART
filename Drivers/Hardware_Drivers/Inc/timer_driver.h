/*
 * timer_driver.h
 *
 *  Created on: May 13, 2024
 *      Author: Kemal
 */

#ifndef HARDWARE_DRIVERS_INC_TIMER_DRIVER_H_
#define HARDWARE_DRIVERS_INC_TIMER_DRIVER_H_

//#include "stm32f0xx_hal.h"
#include "stdint.h"

typedef enum{
	MILLISECONDS,
	MICROSECONDS
}timer_range_ms_or_us_e;

void timer_basic_delay(uint16_t delay);
void timer_reinit_with_new_settings(timer_range_ms_or_us_e timer_range, uint16_t stoptime);
void timer_reset_counter(void);
void timer_init(timer_range_ms_or_us_e timer_choice, uint16_t arr);
void timer_enable(void);
void timer_disable(void);
void timer_enable_interrupt(void);
void timer_disable_interrupt(void);
uint16_t timer_get_counter_value(void);

void send_sensor_data_to_uart_when_everything_is_ok(void);
void send_sensor_data_to_uart_checksum_error(void);
void send_sensor_data_to_uart_read_error(void);
void send_sensor_data_to_uart_reply_error(void);

#endif /* HARDWARE_DRIVERS_INC_TIMER_DRIVER_H_ */