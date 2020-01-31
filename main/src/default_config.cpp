#include "default_config.h"
#include "shape.h"
#include <string>

using namespace std;

Shape DefaultConfig::getRShape() {
  vector<float> rx = {0,.4,.4,.6,.6,1};
  vector<float> ry = {0,0,.2,.2,0,0};
  return Shape(rx,ry);
}

Shape DefaultConfig::getBShape() {
  vector<float> bx = {100,100,412,412,100};
  vector<float> by = {100,412,412,100,100};
  return Shape(bx,by);
}

unsigned DefaultConfig::getDepth() {
  return 4;
}

bool DefaultConfig::getFlip() {
  return true;
}

string DefaultConfig::getOutputFilename() {
  return "fractal.png";
}

unsigned DefaultConfig::getOutputWidth() {
  return 500;
}

unsigned DefaultConfig::getOutputHeight() {
  return 500;
}
