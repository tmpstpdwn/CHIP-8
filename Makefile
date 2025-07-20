CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN = chip8

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

LIBS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
