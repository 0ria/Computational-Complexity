#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Transition {
private:
  std::string actualState;
  std::string actualSymbol;
  std::string actualStackSymbol;
  std::string nextState;
  std::vector<char> newSymbolsToStack;
public:
  Transition(/* args */);
  Transition(std::string);
  ~Transition();
  void printTransition(void);
};