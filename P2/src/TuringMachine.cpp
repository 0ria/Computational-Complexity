#include "../include/TuringMachine.h"

TuringMachine::TuringMachine(/* args */) {}

TuringMachine::TuringMachine(std::vector<std::string> tmData) {
  std::cout << "Datos en el vector de string: " << std::endl;
  for (auto it : tmData) std::cout << it << std::endl;
  std::cout << "********************" << std::endl;

  std::string auxString = "";
  char auxChar;
  std::istringstream iss(tmData[0]);
  while (iss) {
    iss >> auxString;
    State newState(auxString);
    allStates.insert(newState);
  }

  tmData.erase(tmData.begin());
  iss.str("");
  iss.clear();
  iss.str(tmData[0]);

  while (iss) {
    iss >> auxChar;
    machineAlphabet.newSymbol(auxChar);
  }

  tmData.erase(tmData.begin());
  iss.str("");
  iss.clear();
  iss.str(tmData[0]);

  while (iss) {
    iss >> auxChar;
    tapeAlphabet.newSymbol(auxChar);
  }

  tmData.erase(tmData.begin());
  modifyState(tmData[0], INITIAL);

  tmData.erase(tmData.begin());
  setWhiteSymbol(tmData[0]);

  tmData.erase(tmData.begin());
  iss.str("");
  iss.clear();
  iss.str(tmData[0]);
  while (iss) {
    iss >> auxString;
    modifyState(auxString, FINAL);
  }
  /*
  autoamataData.erase(autoamataData.begin());
  for (int i = 0; i < autoamataData.size(); i++)
  {
    Transition newTransition(autoamataData[i]);
    insertTransitionOnState(newTransition);
  }*/
  showStats();
}

TuringMachine::~TuringMachine() {}

void TuringMachine::modifyState(std::string chosenState, bool initial) {
  std::set<State>::iterator it;
  it = allStates.find(chosenState);
  State newInsert = *it;
  if (initial)
    newInsert.setToInitial();
  else
    newInsert.setToFinal();
  allStates.erase(it);
  allStates.insert(newInsert);
}

void TuringMachine::setWhiteSymbol(std::string symbol) {
  if (tapeAlphabet.isSymbolOnAlphabet(symbol[0]))
    whiteSymbol = symbol[0];
  else
    std::cout << "This white symbol is not on the tape Alphabet" << std::endl;
}

void TuringMachine::showStats(void) {
  for (auto it : allStates) {
    std::cout << it.getStateName() << ": " << std::endl;
    std::cout << "Initial: " << it.isStateInitial() << std::endl;
    std::cout << "Final: " << it.isStateFinal() << std::endl << std::endl;
    //std::cout << "Transitions: " << std::endl;
    //it.printEveryTransition();
    std::cout << std::endl;
  }
  std::cout << "Machine's Alphabet: ";
  machineAlphabet.printAlphabet();
  std::cout << "Tape's Alphabet: ";
  tapeAlphabet.printAlphabet();
}