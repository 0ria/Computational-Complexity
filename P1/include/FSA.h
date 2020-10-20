#pragma once
#include "Transition.h"
#include "State.h"
#include "Alphabet.h"
#include "vector"
#include <iostream>
#include <set>
#include <sstream>
#include <stack>

class FSA
{
private:
  std::set<State> allStates;              // Set of every state
  std::set<State> finalStates;
  std::stack<char> symStack;             
  char initSymbStack; 

  Alphabet automAlphabet;
  Alphabet stackAlphabet;

  std::vector<Transition> transitionVector;

public:
  FSA(/* args */);
  FSA(std::vector<std::string>);
  ~FSA();
  void modifyState(std::string, bool);
  void insertOnStack(std::string);
  void showStats(void);
  State getInitialState();
  bool simulate(std::string);
};