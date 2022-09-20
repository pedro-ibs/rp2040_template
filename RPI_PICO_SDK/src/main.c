/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <config.h>
#include <simple_uart.h>

int main() {

	uart_vSetup();

	uart_vSendStringLn("started!");

	while (true) {
		sleep_ms(100);
	}
}
