/* [[INCLUDES]] */

#include "chip8.h"
#include "renderer.h"
#include <stdio.h>

/* [[MAIN]] */

int main(int argc, char *argv[]) {
  if (--argc == 0) {
    fprintf(stderr, "Usage: %s <path to .ch8 rom>!\n", *argv);
    return 1;
  }

  chip8_init(*++argv);
  renderer_init();

  int run = 1;

  while (run) {
    run = renderer_input(keypad);
    chip8_cycle();
    renderer_draw(video);
  }

  return 0;
}

/* [[END]] */
