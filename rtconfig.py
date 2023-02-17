import os

# toolchains options
ARCH        ='risc-v'
CPU         ='virt64'
CROSS_TOOL  ='gcc'

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = os.path.join(os.getcwd(), '..', '..')

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    # EXEC_PATH   = r'/home/leesum/workhome/riscv64-unknown-elf-toolchain/bin'
    EXEC_PATH   = r'/opt/riscv/bin'
else:
    print('Please make sure your toolchains is GNU GCC!')
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

BUILD = 'debug11'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX  = 'riscv64-unknown-elf-'
    CC      = PREFIX + 'gcc'
    CXX     = PREFIX + 'g++'
    AS      = PREFIX + 'gcc'
    AR      = PREFIX + 'ar'
    LINK    = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE    = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY  = PREFIX + 'objcopy'

    DEVICE  = ' -fno-pic -mcmodel=medany -march=rv64im -mabi=lp64'
    CFLAGS  = DEVICE + '  -ffreestanding -fno-common -ffunction-sections -fdata-sections -fstrict-volatile-bitfields '
    AFLAGS  = ' -c' + DEVICE + ' -x assembler-with-cpp'
    LFLAGS  = DEVICE + ' -nostartfiles -Wl,--gc-sections,-Map=rtthread.map,-cref,-u,_start -T link.lds -lc -lm '
    CPATH   = ''
    LPATH   = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -ggdb -fvar-tracking'
        AFLAGS += ' -ggdb'
    else:
        CFLAGS += ' -O3 '

    CXXFLAGS = CFLAGS


NPC_HOME = os.getenv("NPC_HOME")
NEMU_HOME = os.getenv("NEMU_HOME")


RTIMG = os.path.abspath("rtthread.bin")

DUMP_ACTION = OBJDUMP + ' -D -S $TARGET > rtthread.asm\n'
POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' \
            + SIZE + ' $TARGET \n' \
            # + ' make -C ' + NEMU_HOME + ' run IMG='+ RTIMG
               

# $(MAKE) -C $(NPC_HOME)  run  IMG=$(IMAGE).bin