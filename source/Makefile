CC = gcc
CFLAGS = -Wall -std=c99
TARGET = datastructures

# Include paths for headers
INCLUDES = -I../include

# Source files
SOURCES = main.c stack.c queue.c linkedlist.c
OBJECTS = main.o stack.o queue.o linkedlist.o

# Build the entire program
all: $(TARGET)

# Link objects into the main program
$(TARGET): $(OBJECTS)
	@echo "Linking: $(OBJECTS) -> $(TARGET)"
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build completed!"

# Detailed dependencies for each object file:
main.o: main.c ../include/stack.h ../include/queue.h ../include/linkedlist.h
	@echo "Compiling main.c -> main.o"
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o main.o

stack.o: stack.c ../include/stack.h
	@echo "Compiling stack.c -> stack.o"
	$(CC) $(CFLAGS) $(INCLUDES) -c stack.c -o stack.o

queue.o: queue.c ../include/queue.h
	@echo "Compiling queue.c -> queue.o"
	$(CC) $(CFLAGS) $(INCLUDES) -c queue.c -o queue.o

linkedlist.o: linkedlist.c ../include/linkedlist.h
	@echo "Compiling linkedlist.c -> linkedlist.o"
	$(CC) $(CFLAGS) $(INCLUDES) -c linkedlist.c -o linkedlist.o

clean:
	@echo "Cleaning..."
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
