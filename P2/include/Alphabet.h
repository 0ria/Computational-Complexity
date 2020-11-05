#pragma once
#include <set>
#include <string>
#include <iostream>

class Alphabet
{
private:
  std::set<char> symbols;
public:
  Alphabet(/* args */);
  ~Alphabet();
  void newSymbol(char);
  std::set<char> getAllSymbols(void);
  bool isSymbolOnAlphabet(char);
  void printAlphabet(void);
};


