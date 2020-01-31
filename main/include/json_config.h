#ifndef JSON_CONFIG_H
#define JSON_CONFIG_H

#include "i_config.h"
#include "shape.h"
#include "json.hpp"
#include <string>

using namespace std;
using json = nlohmann::json;

class JsonConfig : public IConfig
{
  
private:
  char* m_filename;
  json m_json;
  
  
public:
  JsonConfig( char* filename );
  
  Shape getRShape();
  Shape getBShape();
  unsigned getDepth();
  bool getFlip();
  string getOutputFilename();
  unsigned getOutputWidth();
  unsigned getOutputHeight();
  
  ~JsonConfig(){};
  
};

#endif