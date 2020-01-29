#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>

class Graphics
{
private:
  unsigned m_width;
  unsigned m_height;
  std::vector<unsigned char> m_image;
  
public:
  Graphics( unsigned width, unsigned height );
  
  void writePixel( 
    unsigned x, unsigned y, 
    unsigned r, unsigned g, unsigned b, unsigned a );
    
  void savePng( const char* filename );
  
  unsigned getWidth(){ return m_width; }
  unsigned getHeight(){ return m_height; }
};

#endif