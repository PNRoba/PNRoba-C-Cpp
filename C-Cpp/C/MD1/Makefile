# Makefile - fails, kas ļauj kompilēt jūsu programmu

# Sample Makefile

TARGET = md1

OBJ := $(TARGET)_main.o $(TARGET).o

CC = arm-linux-gnueabi-gcc
AS = arm-linux-gnueabi-as

all:	build test

md1_main.o:
		$(CC) -c md1_main.c 

md1.o:
		$(AS) -alh=$*.lis -L -o md1.o md1.s

build:	$(OBJ) 
		$(CC) -o $(TARGET) $(OBJ)

test:	build
		qemu-arm -L /usr/arm-linux-gnueabi $(TARGET) 10

clean:
		rm -f *.o *.lis
		rm -f $(TARGET)

