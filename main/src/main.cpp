#include <iostream>
#include "graphics.h"

int main(int argc, char *argv[]) {
  unsigned width = 512, height = 512;
  Graphics g(width, height);
  
  for(unsigned y = 0; y < height; y++)
  for(unsigned x = 0; x < width; x++) {
    g.writePixel( x, y, 255 * !(x & y), x ^ y, x | y, 255 );
  }

  g.savePng( "test.png" );
}
