/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include "main.h"
#include <k_api.h>
#include <stdio.h>
#include <stdlib.h>
#include "soc.h"
#include <aos/aos.h>
#include <aos/kernel.h>
#include "lorawan_port.h"
#include "hw.h"


#define DEMO_TASK_STACKSIZE    256 //256*cpu_stack_t = 1024byte
#define DEMO_TASK_PRIORITY     20

extern void soc_init(void);
static ktask_t demo_task_obj;
cpu_stack_t demo_task_buf[DEMO_TASK_STACKSIZE];

#ifdef BLACK_BOARD
	#define RUN_LED_PORT      0x04  //PA4
#else
	#define RUN_LED_PORT      0x11  //PB1
#endif
#define RUN_LED_CONFIG    OUTPUT_PUSH_PULL

#define TIMER_LED_PORT    0x16  //PB6
#define TIMER_LED_CONFIG  OUTPUT_PUSH_PULL

extern void run_led_toggle();
void run_led_toggle()
{  
  static uint32_t test = 0;
  gpio_dev_t gpio_dev;
  
  //run led
  gpio_dev.port = RUN_LED_PORT;
  gpio_dev.config = RUN_LED_CONFIG;
  
  IWDT_Clr();
  test++;
  if (test >= 5000)
  {
    test = 0;
    hal_gpio_output_toggle(&gpio_dev);
  }
}

extern int application_start(void);
void aos_app_entry(void *args)
{
  gpio_dev_t gpio_dev;
  wdg_dev_t wdg_dev;
  
  soc_init();
  
  //wdg init
  wdg_dev.config.timeout = 2000;
  hal_wdg_init(&wdg_dev);
  
  //run led init
  gpio_dev.port = RUN_LED_PORT;
  gpio_dev.config = RUN_LED_CONFIG;
  hal_gpio_init(&gpio_dev);
  
  gpio_dev.port = TIMER_LED_PORT;
  gpio_dev.config = TIMER_LED_CONFIG;
  hal_gpio_init(&gpio_dev);
  
  HW_Init();
  
  printf("lorawan here!\n");
  printf("rhino memory is %d!\n", krhino_global_space_get());
  
  application_start();
}

int main(void)
{
    aos_init();
   
#ifdef CONFIG_AOS_CLI
    extern int aos_cli_init(void);
    aos_cli_init();
#endif

    krhino_task_create(&demo_task_obj, "lorawan app", 0, DEMO_TASK_PRIORITY, 
        50, demo_task_buf, DEMO_TASK_STACKSIZE, (task_entry_t)aos_app_entry, 1);
    
    aos_start();
    
    return 0;
}

