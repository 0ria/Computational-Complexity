#pragma once
#include "Alphabet.h"
#include "State.h"
#include "Tape.h"
#include <string>
#include <vector>
#include <sstream>
#include <set>

class TuringMachine {
 private:
  std::set<State> allStates;
  Tape machineTape;
  Alphabet machineAlphabet;
  Alphabet tapeAlphabet;
  char whiteSymbol;

  std::vector<Transition> transitionVector;

 public:
  TuringMachine(/* args */);
  TuringMachine(std::vector<std::string>);
  ~TuringMachine();
  void setWhiteSymbol(std::string);
  void modifyState(std::string, bool);
  void showStats(void);
  void insertTransitionOnState(Transition);
  bool simulate(State actualState, int counter);
  bool isTransitionValid(Transition, char);
  State getInitialState(void);
  int iterateCounter(Transition, int);
  inline void newTape(std::string tapeInput) { machineTape.setTape(tapeInput, whiteSymbol); };
};
