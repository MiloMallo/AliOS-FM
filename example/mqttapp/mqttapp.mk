
NAME := mqttapp

GLOBAL_DEFINES      += MQTT_TEST ALIOT_DEBUG IOTX_DEBUG USE_LPTHREAD
CONFIG_OTA_CH = mqtt
ifeq ($(STM32_NONSTD_SOCKET), true)
$(NAME)_SOURCES     := mqtt-example-b_l475e.c
$(NAME)_DEFINES     += SENSOR
else
$(NAME)_SOURCES     := mqtt-example.c
endif

#$(NAME)_COMPONENTS += connectivity.mqtt
$(NAME)_COMPONENTS := cli  protocol.linkkit.iotkit  connectivity.mqtt cjson fota netmgr framework.common 

LWIP := 0
ifeq ($(LWIP),1)
$(NAME)_COMPONENTS  += protocols.net
no_with_lwip := 0
endif

ifeq ($(no_tls),1)
GLOBAL_DEFINES += IOTX_WITHOUT_TLS  MQTT_DIRECT
endif

ifeq ($(press_test),1)
GLOBAL_DEFINES += MQTT_PRESS_TEST
endif
