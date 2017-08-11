#!/bin/bash
obj-m += leds.o
KDIR := /home/topeet/linux_kernel_3.0.15/iTop4412_Kernel_public_merge/iTop4412_Kernel_3.0
PWD ?= $(shell pwd)
all:
		make -C $(KDIR) M=$(PWD) modules
clean:
		rm -rf *.o