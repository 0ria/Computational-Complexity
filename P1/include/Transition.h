#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Transition {
private:
  std::string actualState;
  char actualSymbol;
  char actualStackSymbol;
  std::string nextState;
  std::vector<char> newSymbolsToStack;
public:
  Transition(/* args */);
  Transition(std::string);
  ~Transition();
  inline std::string getActualState(void) { return actualState; };
  inline char getActualSymbol(void) { return actualSymbol; };
  inline char getactualStackSymbol(void) { return actualStackSymbol; };
  inline std::string getNextState(void) { return nextState; };
  inline std::vector<char> getNewStackSymbols(void) { return newSymbolsToStack; };

  void printTransition(void);
  //bool isTransitionValid(char);
};