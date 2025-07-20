# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Paths
SRC_DIR = src
OBJ_DIR = obj
BIN = chip8

# Sources and object files
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Libraries for raylib (Linux version; Windows differs!)
LIBS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

# Default rule
all: $(BIN)

# Rule to link the binary
$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

# Rule to compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create obj dir if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
