NAME := board_fm33a0xx-discovery

JTAG := jlink_swd

$(NAME)_TYPE := kernel
MODULE               := fm33a048
HOST_ARCH            := Cortex-M0
HOST_MCU_FAMILY      := fm33a0xx.fm33a048
SUPPORT_BINS         := no

$(NAME)_SOURCES := board.c                 

$(NAME)_COMPONENTS += modules.fs.kv

GLOBAL_INCLUDES += . \
lora \
../../platform/mcu/fm33A0xx/Drivers \
../../platform/mcu/fm33A0xx/Device\Include \
../../include/hal \

GLOBAL_INCLUDES +=  . \
../../device/lora/eml3047_lrwan    \
../../device/lora/sx1276   \

GLOBAL_DEFINES += STDIO_UART=0 CONFIG_NO_TCPIP
GLOBAL_DEFINES += RHINO_CONFIG_TICK_TASK=0 RHINO_CONFIG_WORKQUEUE=0

CONFIG_SYSINFO_DEVICE_NAME := fm33a0xx-discovery

GLOBAL_CFLAGS += -DSYSINFO_OS_VERSION=\"$(CONFIG_SYSINFO_OS_VERSION)\"
GLOBAL_CFLAGS += -DSYSINFO_PRODUCT_MODEL=\"$(CONFIG_SYSINFO_PRODUCT_MODEL)\"
GLOBAL_CFLAGS += -DSYSINFO_DEVICE_NAME=\"$(CONFIG_SYSINFO_DEVICE_NAME)\"

GLOBAL_LDFLAGS  += -L $(SOURCE_ROOT)/board/fm33a0xx-discovery

# Global defines
# HSE_VALUE = FM33A0xx crystal frequency = 16MHz (needed to make UART work correctly)
GLOBAL_DEFINES += $$(if $$(NO_CRLF_STDIO_REPLACEMENT),,CRLF_STDIO_REPLACEMENT)
GLOBAL_CFLAGS  += -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft

WIFI_FIRMWARE_SECTOR_START    := 2      #0x2000
FILESYSTEM_IMAGE_SECTOR_START := 256    #0x100000

# Extra build target in mico_standard_targets.mk, include bootloader, and copy output file to eclipse debug file (copy_output_for_eclipse)
EXTRA_TARGET_MAKEFILES +=  $(MAKEFILES_PATH)/aos_standard_targets.mk
#EXTRA_TARGET_MAKEFILES +=  $(SOURCE_ROOT)/platform/mcu/$(HOST_MCU_FAMILY)/gen_crc_bin.mk
