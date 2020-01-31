#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#include "i_config.h"
#include "shape.h"
#include <string>

using namespace std;

class DefaultConfig : public IConfig
{  

public:
  Shape getRShape();
  Shape getBShape();
  unsigned getDepth();
  bool getFlip();
  string getOutputFilename();
  unsigned getOutputWidth();
  unsigned getOutputHeight();
  
  ~DefaultConfig(){};
};

#endif