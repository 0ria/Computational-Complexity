#include "../include/Transition.h"

Transition::Transition(/* args */) {
}

Transition::~Transition() {
}

Transition::Transition(std::string trans) {
  char auxChar;
  std::istringstream iss(trans);
  iss >> actualState >> actualSymbol >> nextState >> nextSymbol >> move;
}

void Transition::printTransition(void) {
  std::cout << actualState << " " << actualSymbol << " " << nextState << " ";
  std::cout << nextSymbol << " " << move << std::endl;
  std::cout << std::endl;
}