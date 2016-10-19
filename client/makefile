SOURCES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SOURCES))
ELF:=client_func
CC:=gcc
CFLAGS:=-Wall -O2
$(ELF):$(OBJS)
	$(CC) -o $@ $^  -lcrypt

.PHONY:clean

clean:
	rm -rf $(ELF) $(OBJS)
