#pragma once
#include <vector>
#include <string>
#include <iostream>

class Tape {
 private:
  std::vector<char> tapeVector;
 public:
  Tape(/* args */);
  Tape(std::vector<char>);
  ~Tape();
  void setTape(std::string, char);
  void showTape(void);
  std::string getStringTape(void);
  inline std::vector<char> getTape(void) { return tapeVector; };
  inline char getElement(int pos) { return tapeVector[pos]; };
  inline void setElement(int pos, char newChar) { tapeVector[pos] == newChar; };
};
