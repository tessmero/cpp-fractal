#include "fractal.h"
#include "shape.h"
#include <vector>
#include <math.h>

using namespace std;

int sign(float val) {
  return (0 < val) - (val < 0);
}

vector<float>  scalev( vector<float> x, float m ) {  
  vector<float> result(x);
  for( unsigned i = 0 ; i < x.size() ; i++ ) {  
    result[i] *= m;
  }
  return result;
}

vector<float>  translatev( vector<float> x, float dx ) {
  vector<float> result(x);
  for( unsigned i = 0 ; i < x.size() ; i++ ) {
    result[i] += dx;
  }
  return result;
}

vector<float> concatenatev( vector<float>  a, vector<float>  b ) {
  vector<float> result(a);
  result.insert( result.end(), b.begin(), b.end() );
  return result;
}

vector<float> droplastv( vector<float> v ) {
  vector<float> result(v);
  result.pop_back();
  return result;
}

// get the direction of one line segment in the given shape
unsigned dir( Shape s, unsigned i ) {
  vector<float> x = s.getX();
  vector<float> y = s.getY();
  if( x[i] != x[i-1] ){
    return 1-sign( x[i] - x[i-1] );
  } else {
    return 2-sign( y[i] - y[i-1] );
  }
}

// get the length of one line segment in the given shape
float len( Shape s, unsigned i ) {
  vector<float> x = s.getX();
  vector<float> y = s.getY();
  
  return fabs(x[i]-x[i-1]) + fabs(y[i]-y[i-1]);
}

// get a new shape that has been rotated by a multiple of 90 degrees
Shape rotate( Shape s, unsigned r ) {
  if( r == 0 ) {
    return s;
  }
  
  return rotate( 
    Shape( scalev(s.getY(), -1), s.getX() ), 
    r-1 
  );
}

// get a new shape that has been scaled up or down
Shape scale( Shape s, float m ) {
  return Shape(
    scalev( s.getX(), m ),
    scalev( s.getY(), m )
  );
}

// get a new shape that has been translated
Shape translate( Shape s, float tx, float ty ) {
  return Shape(
    translatev( s.getX(), tx ),
    translatev( s.getY(), ty )
  );
}

// get a new shape where the last line segment has been removed
Shape droplast( Shape s ) {
  return Shape(
    droplastv( s.getX() ), 
    droplastv( s.getY() )
  );
}

Shape concatenate( Shape a, Shape b ) {
  return Shape( 
    concatenatev( a.getX(), b.getX() ),
    concatenatev( a.getY(), b.getY() )
  );
}

// get a deeper fractal, where each line segment 
// is replaced by a transformation of r_shape
Shape Fractal::deepen( Shape s ) {
  
  Shape result;
  
  vector<float> x = s.getX();
  vector<float> y = s.getY();
  unsigned n = x.size();
  
  for( unsigned i = 1 ; i < n ; i++ ) {    
    Shape part = translate( 
      scale( rotate( m_rshape, dir(s,i) ), len(s,i) ), 
      x[i-1], y[i-1] );
    
    if( i != (n-1) ){
      part = droplast(part);
    }
      
    result = concatenate( result, part );
  }
  
  return result;
}

void Fractal::flip_rshape() {
  m_rshape = Shape(
    m_rshape.getX(),
    scalev( m_rshape.getY(), -1 )
  );
}

