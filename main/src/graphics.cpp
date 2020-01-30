#include "graphics.h"
#include "color.h"
#include "shape.h"
#include "lodepng.h"
#include <iostream>

Graphics::Graphics( unsigned width, unsigned height ) {
  m_width = width;
  m_height = height;
  m_image.resize(width * height * 4);
}

void Graphics::drawPixel( unsigned x, unsigned y ) {

  if( (x<0) or (x>=m_width) or (y<0) or (y>=m_height) ) {
    return;
  }

  m_image[4 * m_width * y + 4 * x + 0] = m_color.getR();
  m_image[4 * m_width * y + 4 * x + 1] = m_color.getG();
  m_image[4 * m_width * y + 4 * x + 2] = m_color.getB();
  m_image[4 * m_width * y + 4 * x + 3] = m_color.getA();
}

void Graphics::drawHLine( unsigned x1, unsigned x2, unsigned y ) {
  
  if( x1 > x2 ) {
    unsigned t = x2;
    x2 = x1;
    x1 = t;
  }
  
  for(unsigned x = x1; x <= x2; x++) {
    drawPixel( x, y );
  }
}

void Graphics::drawVLine( unsigned x, unsigned y1, unsigned y2 ) {
  
  if( y1 > y2 ) {
    unsigned t = y2;
    y2 = y1;
    y1 = t;
  }
  
  for(unsigned y = y1; y <= y2; y++) {
    drawPixel( x, y );
  }
}

void Graphics::drawShape( Shape s ) {
  std::vector<float> x = s.getX();
  std::vector<float> y = s.getY();
  
  for( unsigned i = 1 ; i < x.size() ; i++ ) {    
    if( x[i-1] != x[i] ){
      drawHLine( x[i-1], x[i], y[i] );
    } else {
      drawVLine( x[i], y[i-1], y[i] );
    }
  }
  
}

void Graphics::fillRect( unsigned x, unsigned y, unsigned w, unsigned h ) {
  
  for(unsigned dy = 0; dy < h; dy++) {
    for(unsigned dx = 0; dx < w; dx++) {
      drawPixel( x+dx, y+dy );
    }
  }
}

void Graphics::savePng( const char* filename ) {
  
  unsigned error = lodepng::encode(filename, m_image, m_width, m_height);

  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}