import os
import sys
import rtconfig

from rtconfig import RTT_ROOT

# set RTT_ROOT
if not os.getenv("RTT_ROOT"): 
    RTT_ROOT="rt-thread"

sys.path = sys.path + [os.path.join(RTT_ROOT, 'tools')]
from building import *

TARGET = 'rtthread.' + rtconfig.TARGET_EXT
DefaultEnvironment(tools=[])
# DefaultEnvironment()
# env=Environment(ENV=os.environ)
env = Environment(tools = ['mingw'],ENV=os.environ, # 获取所有环境变量
                  AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
                  CC = rtconfig.CC, CFLAGS = rtconfig.CFLAGS,
                  CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
                  AR = rtconfig.AR, ARFLAGS = '-rc',
                  LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS)
env.PrependENVPath('PATH', rtconfig.EXEC_PATH)
# env.AppendENVPath('NPC_HOME',os.getenv("NPC_HOME"))
# env.AppendENVPath("XDG_RUNTIME_DIR",os.getenv("XDG_RUNTIME_DIR"))
env['ASCOM'] = env['ASPPCOM']

env.Tool("compilation_db")
env.CompilationDatabase()
# env['NPC_HOME'] = os.getenv("NPC_HOME")
# env['NAVY_HOME'] = os.getenv("NAVY_HOME")
# env['AM_HOME'] = os.getenv("AM_HOME")


# env.AddPostAction()
Export('RTT_ROOT')
Export('rtconfig')
# rtconfig.CPU='virt64'
# rtconfig.ARCH='risc-v'

# prepare building environment
objs = PrepareBuilding(env, RTT_ROOT, has_libcpu = False)

stack_size = 4096

stack_lds = open('link_stacksize.lds', 'w')
if GetDepend('__STACKSIZE__'): stack_size = GetDepend('__STACKSIZE__')
stack_lds.write('__STACKSIZE__ = %d;\r\n' % stack_size)
if GetDepend('RISCV_S_MODE'):  start_addr = int(0x80200000) 
else: start_addr = int(0x80000000)
stack_lds.write('__START_ADDR__ = 0x%x;' % start_addr)

stack_lds.close()

# make a building
DoBuilding(TARGET, objs)




