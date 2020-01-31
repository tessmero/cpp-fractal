#include "json_config.h"
#include "shape.h"
#include "json.hpp"
#include <fstream> 
#include <string>

using namespace std;
using json = nlohmann::json;

JsonConfig::JsonConfig( char* filename ) {
  m_filename = filename;
  ifstream(filename) >> m_json;
}

Shape JsonConfig::getRShape() {
  vector<float> x = m_json["rshape"]["x"].get<vector<float>>();
  vector<float> y = m_json["rshape"]["y"].get<vector<float>>();
  return Shape(x,y);
}

Shape JsonConfig::getBShape() {
  vector<float> x = m_json["bshape"]["x"].get<vector<float>>();
  vector<float> y = m_json["bshape"]["y"].get<vector<float>>();
  return Shape(x,y);
}

unsigned JsonConfig::getDepth() {
  return m_json["depth"]["value"].get<unsigned>();
}

bool JsonConfig::getFlip() {
  return m_json["flip"]["value"].get<bool>();
}

string JsonConfig::getOutputFilename() {
  return m_json["output"]["filename"];
}

unsigned JsonConfig::getOutputWidth() {
  return m_json["output"]["width"].get<unsigned>();
}

unsigned JsonConfig::getOutputHeight() {
  return m_json["output"]["height"].get<unsigned>();
}