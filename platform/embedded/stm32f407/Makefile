BINPATH=/usr/bin

CC=$(BINPATH)/arm-none-eabi-gcc
AR=$(BINPATH)/arm-none-eabi-ar
LD=$(BINPATH)/arm-none-eabi-ld
OBJCOPY=$(BINPATH)/arm-none-eabi-objcopy
SIZE=$(BINPATH)/arm-none-eabi-size

###################################################

# Check for valid float argument
# NOTE that you have to run make clean after
# changing these as hardfloat and softfloat are not
# binary compatible
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

###################################################

vpath %.c .
vpath %.c lib/cmsis_boot
vpath %.c lib/stdperiph/src
vpath %.c ../../../core
vpath %.c ../../../core/screens
vpath %.c ../../../lib/mystdio
vpath %.c ../../../lib/AsciiLib
vpath %.c ../../../lib/LockFreeFifo
vpath %.c ../../../lib/eMIDI/src
vpath %.c ../../../lib/eMIDI/src/hal
vpath %.c ../../../lib/FreeRTOS/Source
vpath %.c ../../../lib/FreeRTOS/Source/portable/MemMang
vpath %.c ../../../lib/FreeRTOS/Source/portable/GCC/ARM_CM4F
vpath %.c src
vpath %.c src/drivers
vpath %.c ../lib/NRF24L01P/src
vpath %.c ../lib/NRF24L01P/hal/stm32f4
vpath %.c lib/tm/tm_stm32f4_gpio
vpath %.c lib/tm/tm_stm32f4_fatfs
vpath %.c lib/tm/tm_stm32f4_fatfs/fatfs
vpath %.c lib/tm/tm_stm32f4_fatfs/fatfs/drivers
vpath %.c lib/tm/tm_stm32f4_fatfs/fatfs/option

vpath %.a lib

CFLAGS  = -std=gnu99 -g -O2 -Wall -Tlink.ld -Xlinker -Map=obj/ucrtos.map
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -nostartfiles -mcpu=cortex-m4
CFLAGS += -Ihdr -Ilib -Ilib/inc
CFLAGS += -Ilib/inc/core
CFLAGS += -Ilib/cmsis/Include
CFLAGS += -Ilib/cmsis_boot
CFLAGS += -Ilib/stdperiph/inc
CFLAGS += -I../../../core
CFLAGS += -I../../../core/screens
CFLAGS += -I../../../lib/mystdio
CFLAGS += -I../../../lib/AsciiLib
CFLAGS += -I../../../lib/LockFreeFifo
CFLAGS += -I../../../lib/FreeRTOS/Source/include
CFLAGS += -I../../../lib/FreeRTOS/Source/portable/GCC/ARM_CM4F
CFLAGS += -I../lib/NRF24L01P/src
CFLAGS += -I../lib/NRF24L01P/hal
CFLAGS += -Ilib/tm
CFLAGS += -Ilib/tm/tm_stm32f4_gpio
CFLAGS += -Ilib/tm/tm_stm32f4_delay
CFLAGS += -Ilib/tm/tm_stm32f4_fatfs
CFLAGS += -Ilib/tm/tm_stm32f4_fatfs/fatfs
CFLAGS += -Ilib/tm/tm_stm32f4_fatfs/fatfs/drivers
CFLAGS += -Ilib/tm/tm_stm32f4_fatfs/fatfs/option

CFLAGS += -ffreestanding # -nostdlib # nostdlib parameter should be set!?

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
else
CFLAGS += -msoft-float
endif

###################################################

OBJDIR=obj
BINDIR=bin
MAIN_SRCS = main.c core_main.c hardware.c nesgamepad.c ssd1289.c stm32f4xx_it.c system_stm32f4xx.c syscalls.c \
            port.c heap_1.c tasks.c list.c timers.c queue.c \
            ff.c ccsbcs.c tm_stm32f4_fatfs.c diskio.c syscall.c tm_stm32f4_gpio.c fatfs_sd_sdio.c \
            lib/cmsis_boot/startup_stm32f4xx.s hal_stm32f4.c # add startup file to build
            # CHECKME: for some reason tm_stm32f4_gpio.c and fatfs_sd_sdio.c have to be added in
            #          MAIN_SRCS or mounting of sd card will fail with error 0x03!?

LIB_SRCS = misc.c stm32f4xx_dma.c stm32f4xx_rcc.c stm32f4xx_adc.c \
	stm32f4xx_exti.c stm32f4xx_rng.c stm32f4xx_can.c stm32f4xx_flash.c \
	stm32f4xx_rtc.c stm32f4xx_crc.c stm32f4xx_fsmc.c stm32f4xx_sdio.c \
	stm32f4xx_cryp_aes.c stm32f4xx_gpio.c stm32f4xx_spi.c \
	stm32f4xx_cryp.c stm32f4xx_hash.c stm32f4xx_syscfg.c \
	stm32f4xx_cryp_des.c stm32f4xx_hash_md5.c stm32f4xx_tim.c \
	stm32f4xx_cryp_tdes.c stm32f4xx_hash_sha1.c  stm32f4xx_usart.c \
	stm32f4xx_dac.c stm32f4xx_i2c.c stm32f4xx_wwdg.c \
	stm32f4xx_dbgmcu.c stm32f4xx_iwdg.c \
	stm32f4xx_dcmi.c stm32f4xx_pwr.c \

UCRTOS_LIB_SRCS = myprintf.c display.c StackBasedFsm.c InputDevice.c core_main.c \
		  SlotBasedMenu.c AsciiLib.c LockFreeFifo.c _examplescreen.c mainmenuscreen.c aboutscreen.c imgtestscreen.c playermenuscreen.c playerscreen.c skateboardscreen.c floppyorgelscreen.c buttontestscreen.c livemodescreen.c sdcardscreen.c images.c helpers.c midifile.c midiplayer.c lut.c nrf24l01p.c

PROJ_NAME=ucrtos
OUTPATH=bin

###################################################

MAIN_OBJS=$(patsubst %.c,$(OBJDIR)/%.o,$(MAIN_SRCS))
LIB_OBJS=$(patsubst %.c,$(OBJDIR)/%.o,$(LIB_SRCS))
UCRTOS_LIB_OBJS=$(patsubst %.c,$(OBJDIR)/%.o,$(UCRTOS_LIB_SRCS))

###################################################

.PHONY: proj flash clean

all: $(OUTPATH)/$(PROJ_NAME).elf

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -L$(OBJDIR) -lstm32f4 -lucrtos -lm

$(OBJDIR)/libstm32f4.a: $(LIB_OBJS)
	$(AR) -r $@ $(LIB_OBJS)

$(OBJDIR)/libucrtos.a: $(UCRTOS_LIB_OBJS)
	$(AR) -r $@ $(UCRTOS_LIB_OBJS)

$(OUTPATH)/$(PROJ_NAME).elf: $(OBJDIR)/libstm32f4.a $(OBJDIR)/libucrtos.a $(MAIN_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -L. -Lobj -lstm32f4 -lucrtos -lm
	$(OBJCOPY) -O ihex $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).bin
	$(SIZE) $@

flash: all
	st-flash write $(BINDIR)/$(PROJ_NAME).bin 0x8000000

proj: $(OUTPATH)/$(PROJ_NAME).elf

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

