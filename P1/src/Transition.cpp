#include "../include/Transition.h"

Transition::Transition(/* args */) {
}

Transition::~Transition() {
}

Transition::Transition(std::string trans) {
  char auxChar;
  std::istringstream iss(trans);
  iss >> actualState >> actualSymbol >> actualStackSymbol >> nextState;
  while (iss >> auxChar) {
    newSymbolsToStack.push_back(auxChar);
  }
}

void Transition::printTransition(void) {
  std::cout << actualState << " " << actualSymbol << " " << actualStackSymbol << " " << nextState << " ";
  for (auto it : newSymbolsToStack)
    std::cout << it << " ";
  std::cout << std::endl;
}