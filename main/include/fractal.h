#ifndef FRACTAL_H
#define FRACTAL_H

#include "shape.h"

class Fractal
{
private:
  Shape m_rshape;
  
public:
  Fractal( Shape rshape ):
    m_rshape(rshape)
  {}
  
  void flip_rshape();
  Shape deepen( Shape s );
};

#endif