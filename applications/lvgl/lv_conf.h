/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-18     Meco Man      First version
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#include <rtconfig.h>

#define LV_USE_PERF_MONITOR         1
#define LV_COLOR_DEPTH              32
#define LV_HOR_RES_MAX              BSP_LCD_HEIGHT
#define LV_VER_RES_MAX              BSP_LCD_WIDTH

#define LV_DPI_DEF 150     /*[px/inch]*/

/* music player demo */
#define LV_USE_DEMO_BENCHMARK           1
#define LV_USE_DEMO_MUSIC               1
#define LV_USE_DEMO_WIDGETS             1
#define LV_USE_DEMO_STRESS              1
#define LV_USE_DEMO_RTT_MUSIC           1
#define LV_DEMO_RTT_MUSIC_AUTO_PLAY     1
#define LV_FONT_MONTSERRAT_12           1
#define LV_FONT_MONTSERRAT_16           1
#define LV_USE_DEMO_KEYPAD_AND_ENCODER  1
#define LV_COLOR_SCREEN_TRANSP          0

#endif
