PWD = $(shell pwd)
TARGET = bt_client
CROSS_COMPILE=
CXXFLAGS = -g -ggdb -rdynamic -Wno-packed-bitfield-compat -fpermissive
CXXFLAGS += -I/usr/include
XLDFLAGS = -lbluetooth -lpthread -rdynamic

build: $(TARGET)

modules-c = $(wildcard *.c)
modules-c-obj = $(subst .c,.o,$(modules-c))
modules-c-dep = $(subst .c,.d,$(modules-c))

modules-cpp = $(wildcard *.cpp)
modules-cpp-obj = $(subst .cpp,.o,$(modules-cpp))
modules-cpp-dep = $(subst .cpp,.d,$(modules-cpp))

modules-dep = $(modules-c-dep) $(modules-cpp-dep)

all: build 

$(modules-c-obj): $(@:%.o=%.c) $(makefile-dep)
	$(CROSS_COMPILE)g++ $(CXXFLAGS) -c $(@:%.o=%.c) -o $@
	$(CROSS_COMPILE)g++ -MM $(CXXFLAGS) $(@:%.o=%.c) > $(@:%.o=%.d)

$(modules-cpp-obj): $(@:%.o=%.cpp) $(makefile-dep)
	$(CROSS_COMPILE)g++ $(CXXFLAGS) -c $(@:%.o=%.cpp) -o $@
	$(CROSS_COMPILE)g++ -MM $(CXXFLAGS) $(@:%.o=%.cpp) > $(@:%.o=%.d)

$(TARGET): $(modules-c-obj) $(modules-cpp-obj)
	$(CROSS_COMPILE)g++ -o $@ $^ $(XLDFLAGS)

get:

init:

distclean:

clean:
	rm -fr $(TARGET) *.d *.o

deploy:

-include $(modules-dep) 
