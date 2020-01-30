#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

using namespace std;

class Shape
{
private:
  vector<float> m_x;
  vector<float> m_y;
  
public:
  Shape(){}

  Shape( vector<float> x, vector<float> y ):
    m_x(x),
    m_y(y)
  {}
  
  vector<float> getX(){ return m_x; }
  vector<float> getY(){ return m_y; }
};

#endif