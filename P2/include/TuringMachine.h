#pragma once
#include "../include/Alphabet.h"
#include "../include/State.h"
#include <string>
#include <vector>
#include <sstream>
#include <set>

class TuringMachine {
 private:
  std::set<State> allStates;
  //Tape machineTape;
  Alphabet machineAlphabet;
  Alphabet tapeAlphabet;
  char whiteSymbol;

 public:
  TuringMachine(/* args */);
  TuringMachine(std::vector<std::string>);
  void setWhiteSymbol(std::string);
  void modifyState(std::string, bool);
  void showStats(void);

  ~TuringMachine();
};
