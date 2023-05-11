/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-17     Meco Man      First version
 */
#include <lvgl.h>
#include "lv_demo_keypad_encoder.h"
#include "lv_demo_widgets.h"
#include "lv_examples.h"
#include "lv_demos.h"

void lv_user_gui_init(void)
{
    /* display demo; you may replace with your LVGL application at here */
    extern void lv_demo_music(void);
    // lv_demo_music();

    // lv_demo_widgets();
    lv_demo_benchmark();
    // lv_demo_keypad_encoder();
    // lv_demo_stress();
    // lv_example_anim_2();
    // lv_example_get_started_2();
}
