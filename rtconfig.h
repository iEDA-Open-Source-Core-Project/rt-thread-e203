#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Project Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 20
#define RT_ALIGN_SIZE 8
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 100
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 16384
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 16384

/* kservice optimization */

#define RT_KPRINTF_USING_LONGLONG
#define RT_DEBUG

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
#define RT_USING_SIGNALS

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SLAB
#define RT_USING_SLAB_AS_HEAP
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 256
#define RT_CONSOLE_DEVICE_NAME "uart"
#define RT_VER_NUM 0x40101
#define ARCH_CPU_64BIT
#define ARCH_RISCV
#define ARCH_RISCV64

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 16384
#define RT_MAIN_THREAD_PRIORITY 10
#define RT_USING_MSH
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 5
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 80
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V1
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_TOUCH

/* Using USB */


/* C/C++ and POSIX layer */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */


/* Interprocess Communication (IPC) */


/* Socket is in the 'Network' category */


/* Network */


/* Utilities */

#define RT_USING_UTEST
#define UTEST_THR_STACK_SIZE 8096
#define UTEST_THR_PRIORITY 20

/* RT-Thread Utestcases */

#define RT_USING_UTESTCASES

/* Utest Self Testcase */

#define UTEST_SELF_PASS_TC

/* Kernel Testcase */

#define UTEST_SLAB_TC
#define UTEST_IRQ_TC
#define UTEST_SEMAPHORE_TC
#define UTEST_EVENT_TC
#define UTEST_TIMER_TC
#define UTEST_MESSAGEQUEUE_TC
#define UTEST_SIGNAL_TC
#define UTEST_MUTEX_TC
#define UTEST_MAILBOX_TC
#define UTEST_THREAD_TC

/* CPP11 Testcase */


/* Utest Serial Testcase */


/* RTT Posix Testcase */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */


/* XML: Extensible Markup Language */


/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */

#define PKG_USING_LVGL
#define PKG_LVGL_THREAD_PRIO 30
#define PKG_LVGL_THREAD_STACK_SIZE 8096
#define PKG_LVGL_DISP_REFR_PERIOD 50
#define PKG_LVGL_USING_EXAMPLES
#define PKG_LVGL_USING_DEMOS
#define PKG_LVGL_USING_V08034
#define PKG_LVGL_VER_NUM 0x08034

/* u8g2: a monochrome graphic library */


/* PainterEngine: A cross-platform graphics application framework written in C language */


/* tools packages */

#define PKG_USING_COREMARK
#define COREMARK_ITERATIONS 3600

/* You may ajust this number to make sure the benchmark runs for at least 10s */

#define PKG_USING_COREMARK_LATEST_VERSION
#define CORE_MARK_HAS_FLOAT 0
#define PKG_USING_DHRYSTONE
#define DHRY_ITERS 320000

/* You may ajust this number to make sure the benchmark runs long enough */

#define PKG_USING_DHRYSTONE_LATEST_VERSION

/* system packages */

/* enhanced kernel services */


/* acceleration: Assembly language or algorithmic acceleration packages */


/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */


/* Micrium: Micrium software products porting for RT-Thread */


/* peripheral libraries and drivers */

/* sensors drivers */


/* touch drivers */


/* Kendryte SDK */


/* AI packages */


/* Signal Processing and Control Algorithm Packages */


/* miscellaneous packages */

/* project laboratory */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */


/* Arduino libraries */


/* Projects */


/* Sensors */


/* Display */


/* Timing */


/* Data Processing */


/* Data Storage */

/* Communication */


/* Device Control */


/* Other */

/* Signal IO */


/* Uncategorized */

#define BOARD_virt
#define RT_USING_USERSPACE

/* RISC-V npc nemu configs */

#define BSP_USING_LVGL
#define BSP_DRV_CLCD
#define BSP_LCD_WIDTH 400
#define BSP_LCD_HEIGHT 300
#define __STACKSIZE__ 26384

#endif
