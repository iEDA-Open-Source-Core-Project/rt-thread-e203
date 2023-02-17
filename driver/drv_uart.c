
#include <rtdevice.h>
#include <rthw.h>

#include "board.h"
#include "drv_uart.h"

#include "amdev.h"
#include "interrupt.h"
#include "rtthread.h"
#include "sbi.h"
#include <stdio.h>

struct device_uart {
  rt_ubase_t hw_base;
  rt_uint32_t irqno;
};

static rt_err_t rt_uart_configure(struct rt_serial_device *serial,
                                  struct serial_configure *cfg);
static rt_err_t uart_control(struct rt_serial_device *serial, int cmd,
                             void *arg);
static int drv_uart_putc(struct rt_serial_device *serial, char c);
static int drv_uart_getc(struct rt_serial_device *serial);

void virt_uart_init(void) {}

/*
 * UART interface
 */
static rt_err_t rt_uart_configure(struct rt_serial_device *serial,
                                  struct serial_configure *cfg) {
  struct device_uart *uart;

  RT_ASSERT(serial != RT_NULL);
  serial->config = *cfg;

  return (RT_EOK);
}

static rt_err_t uart_control(struct rt_serial_device *serial, int cmd,
                             void *arg) {
  struct device_uart *uart;

  uart = serial->parent.user_data;
  rt_uint32_t channel = 1;

  RT_ASSERT(uart != RT_NULL);
  RT_ASSERT(channel != 3);

  switch (cmd) {
  case RT_DEVICE_CTRL_CLR_INT:
    break;

  case RT_DEVICE_CTRL_SET_INT:
    break;
  }

  return (RT_EOK);
}

static int drv_uart_putc(struct rt_serial_device *serial, char c) {
  // while ((uart_read_reg(LSR) & LSR_TX_IDLE) == 0);

  outb(SERIAL_PORT, c);

  return 1;
}

static int drv_uart_getc(struct rt_serial_device *serial) {
  int32_t data = inl(KBD_ADDR + 4);

  if (data != 0) {
    return data;
  }

  return -1;
  // return sbi_console_getchar();
}

static void rt_hw_uart_isr(int irqno, void *param) {
  struct rt_serial_device *serial = (struct rt_serial_device *)param;
  rt_hw_serial_isr(serial, RT_SERIAL_EVENT_RX_IND);
}

struct rt_serial_device serial1;
struct device_uart uart1;

const struct rt_uart_ops _uart_ops = {rt_uart_configure, uart_control,
                                      drv_uart_putc, drv_uart_getc, RT_NULL};



/*
 * UART Initiation
 */
int rt_hw_uart_init(void) {

  struct rt_serial_device *serial;
  struct device_uart *uart;
  struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;
  {
    serial = &serial1;
    uart = &uart1;

    serial->ops = &_uart_ops;
    serial->config = config;
    serial->config.baud_rate = UART_DEFAULT_BAUDRATE;

    uart->hw_base = UART_BASE;
    uart->irqno = UART0_IRQ;

    virt_uart_init();

    rt_hw_serial_register(serial, "uart",
                          RT_DEVICE_FLAG_STREAM |
                              RT_DEVICE_FLAG_RDWR, // | RT_DEVICE_FLAG_INT_RX,
                          uart);
    // rt_hw_interrupt_install(uart->irqno, rt_hw_uart_isr, serial, "uart");

    // rt_hw_interrupt_umask(uart->irqno);
  }

  return 0;
}
INIT_DEVICE_EXPORT(rt_hw_uart_init);