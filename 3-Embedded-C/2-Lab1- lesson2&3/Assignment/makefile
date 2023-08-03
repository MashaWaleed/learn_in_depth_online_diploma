#Mohamed Waleed
#incremental building with makefile
CC=arm-none-eabi-
CFLAGS=-g  -mcpu=arm926ej-s
INCS= -I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn-in-depth

all: $(Project_name).bin
	@echo "=========build is done :)=========="

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe -T linker-script.ld $(AsOBJ) $(OBJ) -o $@

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin