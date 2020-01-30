#include "graphics.h"
#include "fractal.h"
#include <vector>

using namespace std;

// convenience function to declare vectors 
// in a way that works with old compilers
vector<float> vec(float* x, unsigned s){
  vector<float> result(x, x + s); 
  return result;
}


int main(int argc, char *argv[]) {
  
  // rshape (recursive shape) describes the fine details of the fractal
  // must be composed of horizontal and vertical segments
  // must have terminals at (0,0) and (1,0)
  float rx[] = {0,.4,.4,.6,.6,1};
  float ry[] = {0,0,.2,.2,0,0};
  Shape rshape( vec(rx,6), vec(ry,6) );

  // bshape (base shape) describes the overall shape of the fractal
  // must be composed of horizontal and vertical segments
  // units are pixels
  float bx[] = {100,100,412,412,100};
  float by[] = {100,412,412,100,100};
  Shape bshape( vec(bx,5), vec(by,5) );

  // complexity of the fractal
  unsigned depth = 4;

  // generate the fractal
  Fractal f(rshape);
  Shape s(bshape);
  for( unsigned i = 0 ; i < depth ; i++ ) {
    s = f.deepen(s);
    f.flip_rshape(); //(optional) makes the fractal more interesting
  }
  
  // draw the fractal
  unsigned width = 512, height = 512;
  Graphics g(width, height);
  
  g.setColor( Color( 255, 255, 255, 255 ) );
  g.fillRect( 0, 0, width, height );
  
  g.setColor( Color( 0, 0, 0, 255 ) );
  g.drawShape( s );
  
  g.savePng( "test.png" );
}
