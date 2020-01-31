#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "color.h"
#include "shape.h"
#include <vector>
#include <string>

using namespace std;

class Graphics
{
private:
  unsigned m_width;
  unsigned m_height;
  std::vector<unsigned char> m_image;
  Color m_color;
  
public:
  Graphics( unsigned width, unsigned height );
  
  void drawPixel( unsigned x, unsigned y );
  void drawHLine( unsigned x1, unsigned x2, unsigned y );
  void drawVLine( unsigned x, unsigned y1, unsigned y2 );
  void drawShape( Shape s );
  void fillRect( unsigned x, unsigned y, unsigned w, unsigned h );
    
  void savePng( string filename );
  
  void setColor( Color color ){ m_color = color; }
  unsigned getWidth(){ return m_width; }
  unsigned getHeight(){ return m_height; }
};

#endif