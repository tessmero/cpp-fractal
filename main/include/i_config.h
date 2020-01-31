#ifndef ICONFIG_H
#define ICONFIG_H

#include "shape.h"
#include <string>

using namespace std;

class IConfig 
{  

public:  
  virtual Shape getRShape() = 0;
  virtual Shape getBShape() = 0;
  virtual unsigned getDepth() = 0;
  virtual bool getFlip() = 0;
  virtual string getOutputFilename() = 0;
  virtual unsigned getOutputWidth() = 0;
  virtual unsigned getOutputHeight() = 0;
  
  virtual ~IConfig(){};
  
};

#endif