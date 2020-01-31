#include "graphics.h"
#include "fractal.h"
#include "i_config.h"
#include "json_config.h"
#include "default_config.h"

#include <vector>
#include <iostream> 
#include <string>

using namespace std;


Shape buildFractal( IConfig &config ) {
  
  Shape rshape = config.getRShape();
  Shape bshape = config.getBShape();
  unsigned depth = config.getDepth();
  bool flip_rshape = config.getFlip();
  

  cout << "generating fractal..." << endl;
  Fractal f(rshape);
  Shape s(bshape);
  for( unsigned i = 0 ; i < depth ; i++ ) {
    s = f.deepen(s);
    if( flip_rshape ) {
      f.flip_rshape(); 
    }
  }
  
  return s;
}

void drawFractal( Shape s, IConfig &config ) {
  
  unsigned width = config.getOutputWidth();
  unsigned height = config.getOutputHeight();
  string fname = config.getOutputFilename();
  
  Graphics g(width, height);
  
  g.setColor( Color( 255, 255, 255, 255 ) );
  g.fillRect( 0, 0, width, height );
  
  g.setColor( Color( 0, 0, 0, 255 ) );
  g.drawShape( s );
  
  g.savePng( fname );
  cout << "saved fractal image " << fname << endl;
}

int main(int argc, char *argv[]) {
  
  IConfig* config;
  
  if( argc == 1 ) {
    cout << "No arguments given. Using default fractal settings." << endl;
    config = new DefaultConfig();
    
  } else {
    char* json_filename = argv[1];
    cout << "reading fractal configuration file " << json_filename << endl;
    config = new JsonConfig(json_filename);
  }
    
    
  // generate the fractal
  Shape s = buildFractal( *config );
  
  // draw the fractal
  drawFractal( s, *config );
  
}
