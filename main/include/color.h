#ifndef COLOR_H
#define COLOR_H

class Color
{
private:
  unsigned m_r;
  unsigned m_g;
  unsigned m_b;
  unsigned m_a;
  
public:
  Color( unsigned r=0, unsigned g=0, unsigned b=0, unsigned a=255 ):
    m_r(r),
    m_g(g),
    m_b(b),
    m_a(a)
  {}
  
  unsigned getR(){ return m_r; }
  unsigned getG(){ return m_g; }
  unsigned getB(){ return m_b; }
  unsigned getA(){ return m_a; }
};

#endif