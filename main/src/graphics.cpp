#include "graphics.h"
#include "lodepng.h"
#include <iostream>

Graphics::Graphics( unsigned width, unsigned height ) {
  m_width = width;
  m_height = height;
  m_image.resize(width * height * 4);
}

void Graphics::writePixel( 
    unsigned x, unsigned y, 
    unsigned r, unsigned g, unsigned b, unsigned a ) {

  m_image[4 * m_width * y + 4 * x + 0] = r;
  m_image[4 * m_width * y + 4 * x + 1] = g;
  m_image[4 * m_width * y + 4 * x + 2] = b;
  m_image[4 * m_width * y + 4 * x + 3] = a;
}

void Graphics::savePng( const char* filename ) {
  unsigned error = lodepng::encode(filename, m_image, m_width, m_height);

  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}