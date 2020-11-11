#include "../include/Tape.h"

Tape::Tape(/* args */) {}

Tape::Tape(std::vector<char> copyTape) :
tapeVector(copyTape) {

}

Tape::~Tape() {}

void Tape::setTape(std::string input, char whiteSymbol) {
  tapeVector.push_back(whiteSymbol);
  for (char& c : input)
    tapeVector.push_back(c);
  tapeVector.push_back(whiteSymbol);
}

void Tape::showTape(void) {
  for (auto it : tapeVector)
    std::cout << it << " ";
  std::cout << std::endl;
}

std::string Tape::getStringTape(void) {
  std::string aux = "";
  for (auto it : tapeVector)
    aux += it;
  return aux;
}