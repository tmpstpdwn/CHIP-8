#include "chip8.h"
#include "renderer.h"
#include <raylib.h>
#include <stdint.h>

static const int screen_width = VIDEO_WIDTH * SCALE;
static const int screen_height = VIDEO_HEIGHT * SCALE;
static const char *title = "Chip-8";

static const int key_map[16] = {
    KEY_X,     // 0
    KEY_ONE,   // 1
    KEY_TWO,   // 2
    KEY_THREE, // 3
    KEY_Q,     // 4
    KEY_W,     // 5
    KEY_E,     // 6
    KEY_A,     // 7
    KEY_S,     // 8
    KEY_D,     // 9
    KEY_Z,     // A
    KEY_C,     // B
    KEY_FOUR,  // C
    KEY_R,     // D
    KEY_F,     // E
    KEY_V      // F
};

void renderer_init(void) {
  InitWindow(screen_width, screen_height, title);
  SetExitKey(KEY_ESCAPE);
  SetTargetFPS(FPS);
}

void renderer_draw(const uint8_t *video) {
  BeginDrawing();
  ClearBackground(BLACK);
  
  for (int y = 0; y < VIDEO_HEIGHT; y++) {
    for (int x = 0; x < VIDEO_WIDTH; x++) {
      int pixel = video[y * VIDEO_WIDTH + x];
      if (pixel) {
        DrawRectangle(x * SCALE, y * SCALE, SCALE, SCALE, WHITE);
      }
    }
  }

  EndDrawing();
}

int renderer_input(uint8_t *keypad) {
  if (WindowShouldClose()) return 0;
  for (int i = 0; i < 16; i++) {
    keypad[i] = IsKeyDown(key_map[i]);
  }
  return 1;
}
