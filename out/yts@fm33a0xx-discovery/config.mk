AOS_SDK_MAKEFILES           		+= ./out/yts@fm33a0xx-discovery/auto_component/auto_component.mk ./tools/cli/cli.mk ./board/fm33a0xx-discovery/fm33a0xx-discovery.mk ./kernel/hal/hal.mk ./kernel/init/init.mk ././kernel/vfs/device/device.mk ./utility/log/log.mk ./kernel/modules/fs/kv/kv.mk ././platform/arch/arm/armv6m/armv6m.mk ././platform/mcu/fm33a0xx/fm33a048/fm33a048.mk ./kernel/rhino/rhino.mk ./kernel/rhino/test/test.mk ./test/testcase/testcase.mk ./kernel/vcall/vcall.mk ./kernel/vfs/vfs.mk ./kernel/yloop/yloop.mk ./example/yts/yts.mk ./test/yunit/yunit.mk
TOOLCHAIN_NAME            		:= GCC
AOS_SDK_LDFLAGS             		+= -Wl,--gc-sections -Wl,--cref -L .//board/fm33a0xx-discovery -mcpu=cortex-m0plus -mthumb -mthumb-interwork -mlittle-endian -nostartfiles --specs=nosys.specs --specs=nano.specs -u _printf_float -T platform/mcu/fm33a0xx/fm33a048/fm33a0xx_FLASH.ld
AOS_SDK_LDS_FILES                     += 
AOS_SDK_LDS_INCLUDES                  += 
RESOURCE_CFLAGS					+= -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"
AOS_SDK_LINK_SCRIPT         		+= 
AOS_SDK_LINK_SCRIPT_CMD    	 	+= 
AOS_SDK_PREBUILT_LIBRARIES 	 	+= 
AOS_SDK_CERTIFICATES       	 	+= 
AOS_SDK_PRE_APP_BUILDS      		+= 
AOS_SDK_LINK_FILES          		+=                                    
AOS_SDK_INCLUDES           	 	+=                         -I./tools/cli/include -I./board/fm33a0xx-discovery/. -I./board/fm33a0xx-discovery/lora -I./board/fm33a0xx-discovery/../../platform/mcu/fm33A0xx/Drivers -I./board/fm33a0xx-discovery/../../platform/mcu/fm33A0xx/Device\Include -I./board/fm33a0xx-discovery/../../include/hal -I./board/fm33a0xx-discovery/../../device/lora/eml3047_lrwan -I./board/fm33a0xx-discovery/../../device/lora/sx1276 -I./kernel/modules/fs/kv/include -I././platform/arch/arm/armv6m/gcc/m0/ -I././platform/mcu/fm33a0xx/fm33a048/../../arch/arm/armv6m/gcc/m0plus -I././platform/mcu/fm33a0xx/fm33a048/drivers -I././platform/mcu/fm33a0xx/fm33a048/device/include -I././platform/mcu/fm33a0xx/fm33a048/aos -I././platform/mcu/fm33a0xx/fm33a048/../../../include/aos -I./kernel/rhino/core/include -I./kernel/rhino/test/./ -I./test/testcase/include -I./kernel/vcall/./mico/include -I./kernel/vfs/include -I./test/yunit/include -I./include -I./example/yts
AOS_SDK_DEFINES             		+=                   -DBUILD_BIN -DHAVE_NOT_ADVANCED_FORMATE -DCONFIG_AOS_CLI -DSTDIO_UART=0 -DCONFIG_NO_TCPIP -DRHINO_CONFIG_TICK_TASK=0 -DRHINO_CONFIG_WORKQUEUE=0 -DCRLF_STDIO_REPLACEMENT -DAOS_HAL -DAOS_KV -DCONFIG_AOS_KV_MULTIPTN_MODE -DCONFIG_AOS_KV_PTN=6 -DCONFIG_AOS_KV_SECOND_PTN=7 -DCONFIG_AOS_KV_PTN_SIZE=4096 -DCONFIG_AOS_KV_BUFFER_SIZE=8192 -DVCALL_RHINO -DAOS_VFS -DAOS_LOOP
COMPONENTS                		:= auto_component cli board_fm33a0xx-discovery hal kernel_init vfs_device log kv armv6m fm33a048 rhino test testcase vcall vfs yloop yts yunit
PLATFORM_DIRECTORY        		:= fm33a0xx-discovery
APP_FULL                  		:= yts
PLATFORM                  		:= fm33a0xx-discovery
HOST_MCU_FAMILY                  	:= fm33a0xx.fm33a048
SUPPORT_BINS                          := no
APP                       		:= yts
HOST_OPENOCD              		:= fm33a048
JTAG              		        := jlink_swd
HOST_ARCH                 		:= Cortex-M0
NO_BUILD_BOOTLOADER           	:= 
NO_BOOTLOADER_REQUIRED         	:= 
auto_component_LOCATION         := ./out/yts@fm33a0xx-discovery/auto_component/
cli_LOCATION         := ./tools/cli/
board_fm33a0xx-discovery_LOCATION         := ./board/fm33a0xx-discovery/
hal_LOCATION         := ./kernel/hal/
kernel_init_LOCATION         := ./kernel/init/
vfs_device_LOCATION         := ././kernel/vfs/device/
log_LOCATION         := ./utility/log/
kv_LOCATION         := ./kernel/modules/fs/kv/
armv6m_LOCATION         := ././platform/arch/arm/armv6m/
fm33a048_LOCATION         := ././platform/mcu/fm33a0xx/fm33a048/
rhino_LOCATION         := ./kernel/rhino/
test_LOCATION         := ./kernel/rhino/test/
testcase_LOCATION         := ./test/testcase/
vcall_LOCATION         := ./kernel/vcall/
vfs_LOCATION         := ./kernel/vfs/
yloop_LOCATION         := ./kernel/yloop/
yts_LOCATION         := ./example/yts/
yunit_LOCATION         := ./test/yunit/
auto_component_SOURCES          +=  component_init.c testcase_register.c
cli_SOURCES          += cli.c dumpsys.c 
board_fm33a0xx-discovery_SOURCES          += board.c 
hal_SOURCES          += ota.c wifi.c 
kernel_init_SOURCES          += aos_init.c 
vfs_device_SOURCES          += vfs_adc.c vfs_gpio.c vfs_i2c.c vfs_pwm.c vfs_rtc.c vfs_spi.c vfs_uart.c vfs_wdg.c 
log_SOURCES          += log.c 
kv_SOURCES          += kvmgr.c 
armv6m_SOURCES          += gcc/m0/port_c.c gcc/m0/port_s.S 
fm33a048_SOURCES          += ../Device/Source/GCC/startup_FM33A0XX.S ../Device/Source/system_FM33A0XX.c ../Drivers/fm33a0xx_aes.c ../Drivers/fm33a0xx_anac.c ../Drivers/fm33a0xx_btim.c ../Drivers/fm33a0xx_crc.c ../Drivers/fm33a0xx_dma.c ../Drivers/fm33a0xx_etim.c ../Drivers/fm33a0xx_flash.c ../Drivers/fm33a0xx_gpio.c ../Drivers/fm33a0xx_hspi.c ../Drivers/fm33a0xx_i2c.c ../Drivers/fm33a0xx_iwdt.c ../Drivers/fm33a0xx_lcd.c ../Drivers/fm33a0xx_lptim.c ../Drivers/fm33a0xx_pmu.c ../Drivers/fm33a0xx_rcc.c ../Drivers/fm33a0xx_rtc.c ../Drivers/fm33a0xx_scu.c ../Drivers/fm33a0xx_spi.c ../Drivers/fm33a0xx_trng.c ../Drivers/fm33a0xx_u7816.c ../Drivers/fm33a0xx_uart.c ../HAL/soc/flash.c ../HAL/soc/uart.c ../aos/aos.c ../aos/soc_impl.c ../aos/soc_init.c ../aos/trace_impl.c := USE_HAL_DRIVER fm33a048_DEFINES 
rhino_SOURCES          += common/k_fifo.c common/k_trace.c core/k_buf_queue.c core/k_dyn_mem_proc.c core/k_err.c core/k_event.c core/k_idle.c core/k_mm.c core/k_mm_blk.c core/k_mm_debug.c core/k_mutex.c core/k_obj.c core/k_pend.c core/k_queue.c core/k_ringbuf.c core/k_sched.c core/k_sem.c core/k_stats.c core/k_sys.c core/k_task.c core/k_task_sem.c core/k_tick.c core/k_time.c core/k_timer.c core/k_workqueue.c 
test_SOURCES          += core/buf_queue/buf_queue_del.c core/buf_queue/buf_queue_dyn_create.c core/buf_queue/buf_queue_flush.c core/buf_queue/buf_queue_info_get.c core/buf_queue/buf_queue_recv.c core/buf_queue/buf_queue_test.c core/combination/comb_test.c core/combination/sem_event.c core/combination/sem_mutex.c core/combination/sem_queue_buf.c core/event/event_break.c core/event/event_opr.c core/event/event_param.c core/event/event_reinit.c core/event/event_test.c core/mm/mm_break.c core/mm/mm_opr.c core/mm/mm_param.c core/mm/mm_test.c core/mm_blk/mm_blk_break.c core/mm_blk/mm_blk_fragment.c core/mm_blk/mm_blk_opr.c core/mm_blk/mm_blk_param.c core/mm_blk/mm_blk_reinit.c core/mm_blk/mm_blk_test.c core/mutex/mutex_opr.c core/mutex/mutex_param.c core/mutex/mutex_reinit.c core/mutex/mutex_test.c core/queue/queue_back_send.c core/queue/queue_del.c core/queue/queue_flush.c core/queue/queue_info_get.c core/queue/queue_is_full.c core/queue/queue_nowait_recv.c core/queue/queue_test.c core/ringbuf/ringbuf_break.c core/ringbuf/ringbuf_test.c core/sem/sem_break.c core/sem/sem_count.c core/sem/sem_opr.c core/sem/sem_param.c core/sem/sem_reinit.c core/sem/sem_test.c core/sys/sys_opr.c core/sys/sys_test.c core/task/task_del.c core/task/task_misc_test.c core/task/task_sleep.c core/task/task_suspend_test.c core/task/task_test.c core/task/task_yield_test.c core/task_sem/tasksem_count.c core/task_sem/tasksem_opr.c core/task_sem/tasksem_param.c core/task_sem/tasksem_test.c core/time/time_opr.c core/time/time_test.c core/timer/timer_change.c core/timer/timer_create_del.c core/timer/timer_dyn_create_del.c core/timer/timer_start_stop.c core/timer/timer_test.c core/workqueue/workqueue_interface.c core/workqueue/workqueue_test.c test_fw.c test_self_entry.c 
testcase_SOURCES          += yts_main.c 
vcall_SOURCES          += aos/aos_rhino.c 
vfs_SOURCES          += device.c select.c vfs.c vfs_file.c vfs_inode.c vfs_register.c 
yloop_SOURCES          += local_event.c yloop.c 
yts_SOURCES          += main.c 
yunit_SOURCES          += yunit.c 
auto_component_CHECK_HEADERS    += 
cli_CHECK_HEADERS    += 
board_fm33a0xx-discovery_CHECK_HEADERS    += 
hal_CHECK_HEADERS    += 
kernel_init_CHECK_HEADERS    += 
vfs_device_CHECK_HEADERS    += 
log_CHECK_HEADERS    += 
kv_CHECK_HEADERS    += 
armv6m_CHECK_HEADERS    += 
fm33a048_CHECK_HEADERS    += 
rhino_CHECK_HEADERS    += 
test_CHECK_HEADERS    += 
testcase_CHECK_HEADERS    += 
vcall_CHECK_HEADERS    += 
vfs_CHECK_HEADERS    += 
yloop_CHECK_HEADERS    += 
yts_CHECK_HEADERS    += 
yunit_CHECK_HEADERS    += 
auto_component_INCLUDES         := 
cli_INCLUDES         := 
board_fm33a0xx-discovery_INCLUDES         := 
hal_INCLUDES         := 
kernel_init_INCLUDES         := 
vfs_device_INCLUDES         := -I././kernel/vfs/device/../include/device/ -I././kernel/vfs/device/../include/ -I././kernel/vfs/device/../../hal/soc/ -I././kernel/vfs/device/../include/device/ -I././kernel/vfs/device/../include/ -I././kernel/vfs/device/../../hal/soc/
log_INCLUDES         := 
kv_INCLUDES         := 
armv6m_INCLUDES         := 
fm33a048_INCLUDES         := -I././platform/mcu/fm33a0xx/fm33a048/../Device/Include -I././platform/mcu/fm33a0xx/fm33a048/../Drivers -I././platform/mcu/fm33a0xx/fm33a048/../../../../include/hal/soc -I././platform/mcu/fm33a0xx/fm33a048/../aos
rhino_INCLUDES         := 
test_INCLUDES         := 
testcase_INCLUDES         := 
vcall_INCLUDES         := 
vfs_INCLUDES         := 
yloop_INCLUDES         := 
yts_INCLUDES         := 
yunit_INCLUDES         := 
auto_component_DEFINES          := 
cli_DEFINES          := 
board_fm33a0xx-discovery_DEFINES          := 
hal_DEFINES          := 
kernel_init_DEFINES          := 
vfs_device_DEFINES          := 
log_DEFINES          := 
kv_DEFINES          := 
armv6m_DEFINES          := 
fm33a048_DEFINES          := 
rhino_DEFINES          := 
test_DEFINES          := 
testcase_DEFINES          := 
vcall_DEFINES          := 
vfs_DEFINES          := 
yloop_DEFINES          := 
yts_DEFINES          := 
yunit_DEFINES          := 
auto_component_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
cli_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
board_fm33a0xx-discovery_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
hal_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
kernel_init_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
vfs_device_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
log_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
kv_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
armv6m_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
fm33a048_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-strict-aliasing -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-strict-aliasing -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-strict-aliasing
rhino_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
test_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-strict-aliasing -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-strict-aliasing
testcase_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
vcall_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
vfs_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
yloop_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wall -Werror
yts_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" -Wall -Werror -Wno-unused-variable -Wall -Werror -Wno-unused-variable
yunit_CFLAGS           :=   -DSYSINFO_OS_VERSION=\"\" -DSYSINFO_PRODUCT_MODEL=\"\" -DSYSINFO_DEVICE_NAME=\"fm33a0xx-discovery\" -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft       -mcpu=cortex-m0plus -march=armv6-m -mthumb -mthumb-interwork -mlittle-endian -w -DSYSINFO_KERNEL_VERSION=\"AOS-R-1.3.2\"        -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11  -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
auto_component_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
cli_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
board_fm33a0xx-discovery_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
hal_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
kernel_init_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
vfs_device_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
log_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
kv_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
armv6m_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
fm33a048_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
rhino_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
test_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
testcase_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
vcall_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
vfs_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
yloop_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
yts_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
yunit_CXXFLAGS         :=                   -ggdb -Os -Wall -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -fno-rtti -fno-exceptions   -DAOS_SDK_VERSION_MAJOR=3 -DAOS_SDK_VERSION_MINOR=2 -DAOS_SDK_VERSION_REVISION=3 -Iout/yts@fm33a0xx-discovery/resources/ -DPLATFORM=\"fm33a0xx-discovery\" 
auto_component_ASMFLAGS         :=                   -ggdb
cli_ASMFLAGS         :=                   -ggdb
board_fm33a0xx-discovery_ASMFLAGS         :=                   -ggdb
hal_ASMFLAGS         :=                   -ggdb
kernel_init_ASMFLAGS         :=                   -ggdb
vfs_device_ASMFLAGS         :=                   -ggdb
log_ASMFLAGS         :=                   -ggdb
kv_ASMFLAGS         :=                   -ggdb
armv6m_ASMFLAGS         :=                   -ggdb
fm33a048_ASMFLAGS         :=                   -ggdb
rhino_ASMFLAGS         :=                   -ggdb
test_ASMFLAGS         :=                   -ggdb
testcase_ASMFLAGS         :=                   -ggdb
vcall_ASMFLAGS         :=                   -ggdb
vfs_ASMFLAGS         :=                   -ggdb
yloop_ASMFLAGS         :=                   -ggdb
yts_ASMFLAGS         :=                   -ggdb
yunit_ASMFLAGS         :=                   -ggdb
auto_component_RESOURCES        := 
cli_RESOURCES        := 
board_fm33a0xx-discovery_RESOURCES        := 
hal_RESOURCES        := 
kernel_init_RESOURCES        := 
vfs_device_RESOURCES        := 
log_RESOURCES        := 
kv_RESOURCES        := 
armv6m_RESOURCES        := 
fm33a048_RESOURCES        := 
rhino_RESOURCES        := 
test_RESOURCES        := 
testcase_RESOURCES        := 
vcall_RESOURCES        := 
vfs_RESOURCES        := 
yloop_RESOURCES        := 
yts_RESOURCES        := 
yunit_RESOURCES        := 
auto_component_MAKEFILE         := ./out/yts@fm33a0xx-discovery/auto_component/auto_component.mk
cli_MAKEFILE         := ./tools/cli/cli.mk
board_fm33a0xx-discovery_MAKEFILE         := ./board/fm33a0xx-discovery/fm33a0xx-discovery.mk
hal_MAKEFILE         := ./kernel/hal/hal.mk
kernel_init_MAKEFILE         := ./kernel/init/init.mk
vfs_device_MAKEFILE         := ././kernel/vfs/device/device.mk
log_MAKEFILE         := ./utility/log/log.mk
kv_MAKEFILE         := ./kernel/modules/fs/kv/kv.mk
armv6m_MAKEFILE         := ././platform/arch/arm/armv6m/armv6m.mk
fm33a048_MAKEFILE         := ././platform/mcu/fm33a0xx/fm33a048/fm33a048.mk
rhino_MAKEFILE         := ./kernel/rhino/rhino.mk
test_MAKEFILE         := ./kernel/rhino/test/test.mk
testcase_MAKEFILE         := ./test/testcase/testcase.mk
vcall_MAKEFILE         := ./kernel/vcall/vcall.mk
vfs_MAKEFILE         := ./kernel/vfs/vfs.mk
yloop_MAKEFILE         := ./kernel/yloop/yloop.mk
yts_MAKEFILE         := ./example/yts/yts.mk
yunit_MAKEFILE         := ./test/yunit/yunit.mk
auto_component_PRE_BUILD_TARGETS:= 
cli_PRE_BUILD_TARGETS:= 
board_fm33a0xx-discovery_PRE_BUILD_TARGETS:= 
hal_PRE_BUILD_TARGETS:= 
kernel_init_PRE_BUILD_TARGETS:= 
vfs_device_PRE_BUILD_TARGETS:= 
log_PRE_BUILD_TARGETS:= 
kv_PRE_BUILD_TARGETS:= 
armv6m_PRE_BUILD_TARGETS:= 
fm33a048_PRE_BUILD_TARGETS:= 
rhino_PRE_BUILD_TARGETS:= 
test_PRE_BUILD_TARGETS:= 
testcase_PRE_BUILD_TARGETS:= 
vcall_PRE_BUILD_TARGETS:= 
vfs_PRE_BUILD_TARGETS:= 
yloop_PRE_BUILD_TARGETS:= 
yts_PRE_BUILD_TARGETS:= 
yunit_PRE_BUILD_TARGETS:= 
auto_component_PREBUILT_LIBRARY := 
cli_PREBUILT_LIBRARY := 
board_fm33a0xx-discovery_PREBUILT_LIBRARY := 
hal_PREBUILT_LIBRARY := 
kernel_init_PREBUILT_LIBRARY := 
vfs_device_PREBUILT_LIBRARY := 
log_PREBUILT_LIBRARY := 
kv_PREBUILT_LIBRARY := 
armv6m_PREBUILT_LIBRARY := 
fm33a048_PREBUILT_LIBRARY := 
rhino_PREBUILT_LIBRARY := 
test_PREBUILT_LIBRARY := 
testcase_PREBUILT_LIBRARY := 
vcall_PREBUILT_LIBRARY := 
vfs_PREBUILT_LIBRARY := 
yloop_PREBUILT_LIBRARY := 
yts_PREBUILT_LIBRARY := 
yunit_PREBUILT_LIBRARY := 
auto_component_TYPE             := kernel
cli_TYPE             := kernel
board_fm33a0xx-discovery_TYPE             := kernel
hal_TYPE             := kernel
kernel_init_TYPE             := kernel
vfs_device_TYPE             := 
log_TYPE             := share
kv_TYPE             := kernel
armv6m_TYPE             := 
fm33a048_TYPE             := kernel
rhino_TYPE             := kernel
test_TYPE             := 
testcase_TYPE             := 
vcall_TYPE             := kernel
vfs_TYPE             := kernel
yloop_TYPE             := kernel
yts_TYPE             := 
yunit_TYPE             := 
AOS_SDK_UNIT_TEST_SOURCES   		:=                                    
ALL_RESOURCES             		:= 
INTERNAL_MEMORY_RESOURCES 		:= 
EXTRA_TARGET_MAKEFILES 			:=    .//build/aos_standard_targets.mk
APPS_START_SECTOR 				:=  
BOOTLOADER_FIRMWARE				:=  
ATE_FIRMWARE				        :=  
APPLICATION_FIRMWARE				:=  
PARAMETER_1_IMAGE					:=  
PARAMETER_2_IMAGE					:=  
FILESYSTEM_IMAGE					:=  
WIFI_FIRMWARE						:=  
BT_PATCH_FIRMWARE					:=  
AOS_ROM_SYMBOL_LIST_FILE 		:= 
AOS_SDK_CHIP_SPECIFIC_SCRIPT		:=                  
AOS_SDK_CONVERTER_OUTPUT_FILE	:=                  
AOS_SDK_FINAL_OUTPUT_FILE 		:=                  
AOS_RAM_STUB_LIST_FILE 			:= 
PING_PONG_OTA 					:= 
