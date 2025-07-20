// Renderer.h
#ifndef RENDERER_H
#define RENDERER_H

// Includes
#include "stdint.h"

// Defines
#define SCALE 10
#define FPS 60

// Fns
void renderer_init(void);
void renderer_draw(const uint8_t *video);
int renderer_input(uint8_t *keypad);

#endif
