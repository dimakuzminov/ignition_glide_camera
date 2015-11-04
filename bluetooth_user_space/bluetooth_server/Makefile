PWD = $(shell pwd)
TARGET = bt_server
CROSS_COMPILE=$(PWD)/../../buildroot/output/host/usr/bin/arm-buildroot-linux-gnueabihf-
CXXFLAGS = -g -ggdb -rdynamic
CXXFLAGS += -I$(PWD)/../../buildroot/output/host/usr/arm-buildroot-linux-gnueabihf/sysroot/usr/include/
XLDFLAGS = -lbluetooth -lpthread -static-libstdc++ -static-libgcc -rdynamic
XLDFLAGS += -L$(PWD)/../../buildroot/output/target/usr/lib/
XLDFLAGS += -L$(PWD)/../../buildroot/output/host/usr/arm-buildroot-linux-gnueabihf/sysroot/usr/lib
XLDFLAGS += -L$(PWD)/../../buildroot/output/host/usr/arm-buildroot-linux-gnueabihf/sysroot/usr/lib
XLDFLAGS += -L$(PWD)/../../buildroot/output/host/usr/arm-buildroot-linux-gnueabihf/sysroot//usr/lib

export LD_LIBRARY_PATH:=$(PWD)/../../buildroot/output/host/usr/lib/:$(LD_LIBRARY_PATH)

build: $(TARGET)

modules-c = $(wildcard *.c)
modules-c-obj = $(subst .c,.o,$(modules-c))
modules-c-dep = $(subst .c,.d,$(modules-c))

modules-dep = $(modules-c-dep)

all: build 

$(modules-c-obj): $(@:%.o=%.c) $(makefile-dep)
	$(CROSS_COMPILE)gcc $(CXXFLAGS) -c $(@:%.o=%.c) -o $@
	$(CROSS_COMPILE)gcc -MM $(CXXFLAGS) $(@:%.o=%.c) > $(@:%.o=%.d)

$(TARGET): $(modules-c-obj)
	$(CROSS_COMPILE)gcc -o $@ $^ $(XLDFLAGS)

get:

init:

distclean:

clean:
	rm -fr $(TARGET) *.d *.o

deploy:

-include $(modules-dep) 
