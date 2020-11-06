#pragma once
#include <vector>
#include <string>
#include <iostream>

class Tape {
 private:
  std::vector<char> tapeVector;
 public:
  Tape(/* args */);
  ~Tape();
  void setTape(std::string, char);
  void showTape(void);
};
