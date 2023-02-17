/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-05-20     bigmagic     first version
 */

#ifndef __DRV_UART_H__
#define __DRV_UART_H__
#include <rtthread.h>

#define UART0_IRQ   (10)

#define UART_DEFAULT_BAUDRATE               115200

#define UART_BASE            (0x10000000L)


#define uart_read_reg(reg) (*(UART_REG(reg)))
#define uart_write_reg(reg, v) (*(UART_REG(reg)) = (v))

int rt_hw_uart_init(void);

#endif /* __DRV_UART_H__ */
