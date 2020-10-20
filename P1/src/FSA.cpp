#include "../include/FSA.h"

FSA::FSA(/* args */) {

}

FSA::FSA(std::vector<std::string> autoamataData) {
   std::cout << "Datos en el vector de string: " << std::endl;
  for (auto it : autoamataData)
    std::cout << it << std::endl;
  std::cout << "********************" << std::endl;

  std::string auxString = "";
  char auxChar;
  std::istringstream iss(autoamataData[0]);
  while (iss) {
    iss >> auxString;
    State newState(auxString);
    allStates.insert(newState);
  }

  autoamataData.erase(autoamataData.begin());
  iss.str("");
  iss.clear();
  iss.str(autoamataData[0]);

  while (iss) {
    iss >> auxChar;
    automAlphabet.newSymbol(auxChar);
  }

  autoamataData.erase(autoamataData.begin());
  iss.str("");
  iss.clear();
  iss.str(autoamataData[0]);

  while (iss) {
    iss >> auxChar;
    stackAlphabet.newSymbol(auxChar);
  }

  //Initial State
  autoamataData.erase(autoamataData.begin());
  modifyState(autoamataData[0], INITIAL);

  // initial element on Stack
  autoamataData.erase(autoamataData.begin());
  insertOnStack(autoamataData[0]);

  // Final States
  autoamataData.erase(autoamataData.begin());
  iss.str("");
  iss.clear();
  iss.str(autoamataData[0]);
  while (iss) {
    iss >> auxString;
    modifyState(auxString, FINAL);
  }

  autoamataData.erase(autoamataData.begin());
  for (int i = 0; i < autoamataData.size(); i++) {
    Transition newTransition(autoamataData[i]);
    transitionVector.push_back(newTransition);
  }


  showStats();
}

FSA::~FSA() {

}

void FSA::modifyState(std::string initialState, bool initial) {
  std::set<State>::iterator it;
  it = allStates.find(initialState);
  auto newInsert = *it;
  if (initial)
    newInsert.setToInitial();
  else
    newInsert.setToFinal();
  allStates.erase(it);
  allStates.insert(newInsert);
}

void FSA::insertOnStack(std::string stackSymbol) {
  if (stackAlphabet.isSymbolOnAlphabet(stackSymbol[0])) {
    symStack.push(stackSymbol[0]);
  }
  else 
    std::cout << "The symbol is not on the stack Alphabet" << std::endl;
}

void FSA::showStats(void) {
  for (auto it : allStates) {
    std::cout << it.getStateName() << ": " << std::endl;
    std::cout << "Initial: " << it.isStateInitial() << std::endl;
    std::cout << "Final: " << it.isStateFinal() << std::endl;
  }
  std::cout << "Automata's Alphabet: ";
  automAlphabet.printAlphabet();
  std::cout << "Stack's Alphabet: ";
  stackAlphabet.printAlphabet();
  std::cout << "Current stack size + top element: " << symStack.size() << " : " << symStack.top() << std::endl;

  for (auto it : transitionVector) {
    it.printTransition();
  }
}

State FSA::getInitialState(void) {
  for (State it : allStates) {
    if (it.isStateInitial())
      return it;
  }
}

bool FSA::simulate(std::string input) {
  State currentState = getInitialState();
  for (char& c : input) {
    if (automAlphabet.isSymbolOnAlphabet(c)) {

    }
  }
  return true;
}