DEVICE = STM32F303xB
FLASH  = 0x08000000

USE_ST_CMSIS = true

# use system toolchain
TOOLCHAIN_PATH =

# Include the main makefile
include ./STM32-base/make/common.mk

flash: all
	openocd -f interface/stlink-v2.cfg -f target/stm32f3x.cfg -c "program $(ELF_FILE_PATH) verify reset exit"