BSP_ROOT ?= /home/leesum/workhome/rt-thread-master/bsp/qemu-virt64-riscv
RTT_ROOT ?= /home/leesum/workhome/rt-thread-master

CROSS_COMPILE ?=/opt/riscv/bin/riscv64-unknown-elf-

CFLAGS := -fno-pic -mcmodel=medany -march=rv64im -mabi=lp64 -fvar-tracking -ffreestanding -fno-common -ffunction-sections -fdata-sections -fstrict-volatile-bitfields  -O0 -ggdb
AFLAGS := -c -fno-pic -mcmodel=medany -march=rv64im -mabi=lp64 -x assembler-with-cpp -ggdb
LFLAGS := -fno-pic -mcmodel=medany -march=rv64im -mabi=lp64 -nostartfiles -Wl,--gc-sections,-Map=rtthread.map,-cref,-u,_start -T link.lds -lc -lm 
CXXFLAGS := -fno-pic -mcmodel=medany -march=rv64im -mabi=lp64 -fvar-tracking -ffreestanding -fno-common -ffunction-sections -fdata-sections -fstrict-volatile-bitfields  -O0 -ggdb
EXTERN_LIB := -lc -lm 

CPPPATHS :=-I$(BSP_ROOT)/applications \
	-I$(RTT_ROOT)/components/libc/compilers/common/include \
	-I$(RTT_ROOT)/components/libc/compilers/newlib \
	-I$(BSP_ROOT)/packages/CoreMark-latest \
	-I$(RTT_ROOT)/libcpu/risc-v/virt64 \
	-I$(RTT_ROOT)/components/drivers/include \
	-I$(BSP_ROOT)/packages/Dhrystone-latest \
	-I$(BSP_ROOT)/driver \
	-I$(RTT_ROOT)/components/dfs/include \
	-I$(RTT_ROOT)/components/dfs/filesystems/devfs \
	-I$(RTT_ROOT)/components/dfs/filesystems/romfs \
	-I$(RTT_ROOT)/components/finsh \
	-I$(BSP_ROOT) \
	-I$(RTT_ROOT)/include \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/core \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/font \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/hal \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/misc \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/widgets \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/arm2d \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/nxp \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/sdl \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/stm32_dma2d \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/sw \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/swm341_dma2d \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/nxp/pxp \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/draw/nxp/vglite \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/layouts \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/themes \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/layouts/flex \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/layouts/grid \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/bmp \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/ffmpeg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/freetype \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/fsdrv \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/gif \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/png \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/qrcode \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/rlottie \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/libs/sjpg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/fragment \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/gridnav \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/ime \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/imgfont \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/monkey \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/msg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/others/snapshot \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/themes/basic \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/themes/default \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/themes/mono \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/animimg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/calendar \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/chart \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/colorwheel \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/imgbtn \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/keyboard \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/led \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/list \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/menu \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/meter \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/msgbox \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/span \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/spinbox \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/spinner \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/tabview \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/tileview \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/src/extra/widgets/win \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/anim \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/event \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/get_started \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/layouts \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/porting \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/scroll \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/styles \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/widgets \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/layouts/flex \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/layouts/grid \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/bmp \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/ffmpeg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/freetype \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/gif \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/png \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/qrcode \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/rlottie \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/libs/sjpg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/fragment \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/gridnav \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/ime \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/imgfont \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/monkey \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/msg \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/examples/others/snapshot \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/benchmark \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/keypad_encoder \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/music \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/stress \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/widgets \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/demos/music/assets \
	-I$(BSP_ROOT)/packages/LVGL-v8.3.4/env_support/rt-thread \
	-I$(RTT_ROOT)/components/libc/posix/io/poll \
	-I$(RTT_ROOT)/components/libc/posix/io/stdio \
	-I$(RTT_ROOT)/components/libc/posix/ipc \
	-I$(RTT_ROOT)/components/utilities/utest \
	-I$(RTT_ROOT)/examples/utest/testcases/kernel \
	-I$(RTT_ROOT)/examples/utest/testcases/utest 

DEFINES := -DHAVE_CCONFIG_H -DRT_USING_LIBC -DRT_USING_NEWLIB -D_POSIX_C_SOURCE=1 -D__RTTHREAD__
