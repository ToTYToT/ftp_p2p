SOURCES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SOURCES))
ELF:=server_func
CC:=gcc
CFLAGS:=-Wall -O2
$(ELF):$(OBJS)
	$(CC) -o $@ $^  -lpthread -I /usr/include/mysql/ -lmysqlclient

.PHONY:clean

clean:
	rm -rf $(ELF) $(OBJS)
