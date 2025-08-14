CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -I../include
LDFLAGS := -lm

OBJS := main.o linkedlist.o queue.o stack.o

.PHONY: all clean
all: main

main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main
