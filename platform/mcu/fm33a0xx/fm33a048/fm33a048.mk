NAME := fm33a048

HOST_OPENOCD := fm33a048

SPI_WIFI_ENABLED := false

$(NAME)_TYPE := kernel

$(NAME)_COMPONENTS += platform/arch/arm/armv6m
# $(NAME)_COMPONENTS += libc rhino hal netmgr framework.common mbedtls cjson cli digest_algorithm
$(NAME)_COMPONENTS += rhino


GLOBAL_DEFINES += CONFIG_AOS_KV_MULTIPTN_MODE
GLOBAL_DEFINES += CONFIG_AOS_KV_PTN=6
GLOBAL_DEFINES += CONFIG_AOS_KV_SECOND_PTN=7
GLOBAL_DEFINES += CONFIG_AOS_KV_PTN_SIZE=4096
GLOBAL_DEFINES += CONFIG_AOS_KV_BUFFER_SIZE=8192

GLOBAL_INCLUDES += ../../arch/arm/armv6m/gcc/m0plus
                    
GLOBAL_INCLUDES += drivers \
                   device/include    \
                   aos\
                   ../../../include/aos

GLOBAL_CFLAGS += -mcpu=cortex-m0plus \
                 -march=armv6-m \
                 -mthumb -mthumb-interwork \
                 -mlittle-endian

GLOBAL_CFLAGS += -w

GLOBAL_LDFLAGS += -mcpu=cortex-m0plus        \
                  -mthumb -mthumb-interwork \
                  -mlittle-endian \
                  -nostartfiles \
                  --specs=nosys.specs \
                  $(CLIB_LDFLAGS_NANO_FLOAT)

$(NAME)_CFLAGS  += -Wall -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-implicit-function-declaration
$(NAME)_CFLAGS  += -Wno-type-limits -Wno-sign-compare -Wno-pointer-sign -Wno-uninitialized
$(NAME)_CFLAGS  += -Wno-return-type -Wno-unused-function -Wno-unused-but-set-variable
$(NAME)_CFLAGS  += -Wno-unused-value -Wno-strict-aliasing

$(NAME)_INCLUDES := \
../Device/Include \
../Drivers \
../../../../include/hal/soc\
../aos
$(NAME)_SOURCES := \
../aos/aos.c \
../aos/soc_impl.c \
../aos/soc_init.c \
../aos/trace_impl.c \
../Device/Source/GCC/startup_FM33A0XX.S\
../Device/Source/system_FM33A0XX.c\
../Drivers/fm33a0xx_aes.c\
../Drivers/fm33a0xx_anac.c\
../Drivers/fm33a0xx_btim.c\
../Drivers/fm33a0xx_crc.c\
../Drivers/fm33a0xx_dma.c\
../Drivers/fm33a0xx_etim.c\
../Drivers/fm33a0xx_flash.c\
../Drivers/fm33a0xx_gpio.c\
../Drivers/fm33a0xx_hspi.c\
../Drivers/fm33a0xx_i2c.c\
../Drivers/fm33a0xx_iwdt.c\
../Drivers/fm33a0xx_lcd.c\
../Drivers/fm33a0xx_lptim.c\
../Drivers/fm33a0xx_pmu.c\
../Drivers/fm33a0xx_rcc.c\
../Drivers/fm33a0xx_rtc.c\
../Drivers/fm33a0xx_scu.c\
../Drivers/fm33a0xx_spi.c\
../Drivers/fm33a0xx_trng.c\
../Drivers/fm33a0xx_u7816.c\
../Drivers/fm33a0xx_uart.c\
../Drivers/fm33a0xx_anac.c\
../HAL/soc/flash.c\
../HAL/soc/uart.c\
$(NAME)_DEFINES := \
USE_HAL_DRIVER 

GLOBAL_LDFLAGS += -T platform/mcu/fm33a0xx/fm33a048/fm33a0xx_FLASH.ld
