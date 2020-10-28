#include "../include/Alphabet.h"

Alphabet::Alphabet(/* args */)
{
  //symbols.insert('.');
}

Alphabet::~Alphabet()
{
}

void Alphabet::newSymbol(char sym) {
  symbols.insert(sym);
}

std::set<char> Alphabet::getAllSymbols(void) {
  return symbols;
}

bool Alphabet::isSymbolOnAlphabet(char sym) {
  std::set<char>::iterator it;
  it = symbols.find(sym);
  if (it != symbols.end())
    return true;
  else 
    return false;
}

void Alphabet::printAlphabet(void) {
  for (auto it : symbols) 
    std::cout << it << " ";
  std::cout << std::endl;
}