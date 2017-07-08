ARCH = arm-linux-gnueabihf
CC = ${ARCH}-g++
ARCH_LIB_LOCATION = /usr/lib/${ARCH}


CFLAGS=-I./ -I/usr/include/libusb-1.0 -I/usr/include/python2.7 -fPIC
LDFLAGS=-shared -Wl,--unresolved-symbols=report-all -Wl,-soname,$@ -Wl,-rpath,${ARCH_LIB_LOCATION} -L${ARCH_LIB_LOCATION} -lusb-1.0 -lboost_thread -lboost_system -lboost_chrono -lboost_python -lpython2.7 

OBJS = PixyReader.o
INCS = PixyReader.h
TGT = PixyBlockReader.so
PIXYLIB=/usr/local/lib/libpixyusb.a

all : $(TGT)

%.o : %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TGT) :  $(OBJS)
	$(CC) $^ $(PIXYLIB) $(LDFLAGS) -o $@

clean :
	rm -f *.o $(TGT)

