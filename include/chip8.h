// Chip8.h
#ifndef CHIP8_H
#define CHIP8_H

// Includes
#include <stdint.h>

// Defines
#define MEM_SIZE 4096
#define FONTSET_SIZE 80

#define VIDEO_WIDTH 64
#define VIDEO_HEIGHT 32

#define START_ADDRESS 0x200
#define FONTSET_START_ADDRESS 0x50

// Vars
extern uint8_t video[VIDEO_HEIGHT * VIDEO_WIDTH];
extern uint8_t keypad[16];

// Typedefs
typedef void (*chip8_fn)(void);

// Fns
void chip8_init(const char *file_name);
void chip8_cycle(void);

#endif
