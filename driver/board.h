/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-01-30     lizhirui     first version
 */

#ifndef BOARD_H__
#define BOARD_H__

#include <rtconfig.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;
extern unsigned int _heap_end;


#define RT_HW_HEAP_BEGIN ((void *)&__bss_end)
#define RT_HW_HEAP_END ((void *)&_heap_end)

// #define RT_HW_HEAP_END ((void *)(((rt_size_t)RT_HW_HEAP_BEGIN) + 40 * 1024))
// #define RT_HW_PAGE_START RT_HW_HEAP_END
// #define RT_HW_PAGE_END ((void *)(((rt_size_t)RT_HW_PAGE_START) + 20 * 1024))

void rt_hw_board_init(void);


#endif
