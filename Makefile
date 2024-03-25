MODULE_NAME = usb-serial

DEBUG_FLGS = -O -g
ccflags-y += $(DEBUG_FLGS)

obj-m += $(MODULE_NAME).o
#mymod-objs := $(addsuffix .o, $(addprefix $(SOURCE_DIR), $(SOURCES)))

KVERSION = $(shell uname -r)
PWD := $(CURDIR)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean