#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Transition {
private:
  std::string actualState;
  std::string nextState;
  char actualSymbol;
  char nextSymbol;
  char move;
  
public:
  Transition(/* args */);
  Transition(std::string);
  ~Transition();
  inline std::string getActualState(void) { return actualState; };
  inline char getActualSymbol(void) { return actualSymbol; };
  inline char getNextSymbol(void) { return nextSymbol; };
  inline std::string getNextState(void) { return nextState; };
  inline char getMove(void) { return move; };

  void printTransition(void);
  //bool isTransitionValid(char);
};