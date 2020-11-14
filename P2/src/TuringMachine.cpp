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

  tmData.erase(tmData.begin());
  for (int i = 0; i < tmData.size(); i++) {
    Transition newTransition(tmData[i]);
    insertTransitionOnState(newTransition);
  }
}

TuringMachine::~TuringMachine() {}

void TuringMachine::insertTransitionOnState(Transition newTrans) {
  for (State st : allStates) {
    if (st.getStateName() == newTrans.getActualState()) {
      State newInsert = st;
      newInsert.setNewTransition(newTrans);
      allStates.erase(st);
      allStates.insert(newInsert);
    }
  }
}

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

State TuringMachine::getInitialState(void) {
  for (State st : allStates)
    if (st.isStateInitial()) return st;
  return State();
}

void TuringMachine::showStats(void) {
  for (auto it : allStates) {
    std::cout << it.getStateName() << ": " << std::endl;
    std::cout << "Initial: " << it.isStateInitial() << std::endl;
    std::cout << "Final: " << it.isStateFinal() << std::endl << std::endl;
    std::cout << "Transitions: " << std::endl;
    it.printEveryTransition();
    std::cout << std::endl;
  }
  std::cout << "Machine's Alphabet: ";
  machineAlphabet.printAlphabet();
  std::cout << "Tape's Alphabet: ";
  tapeAlphabet.printAlphabet();

  std::cout << "Tape: ";
  machineTape.showTape();
  std::cout << std::endl;
}

bool TuringMachine::isTransitionValid(Transition tr, char actualChar) {
  if (tr.getActualSymbol() == actualChar)
    return true;
  else
    return false;
}

int TuringMachine::iterateCounter(Transition tr, int counter) {
  tr.getMove() == 'R' ? counter++
                      : tr.getMove() == 'L' ? counter-- : counter;
  return counter;
}

bool TuringMachine::simulate(State actualState, int counter) {
  bool stopCondition = false;
  bool foundTransition = false;
  while (stopCondition != true) {
    for (Transition tr : actualState.getTransitions()) {
      if (isTransitionValid(tr, machineTape.getElement(counter))) {
        foundTransition = true;
        machineTape.setElement(counter, tr.getNextSymbol());
        counter = iterateCounter(tr, counter);
        actualState = *allStates.find(tr.getNextState());
        break;
      }
    }
    if (foundTransition != true)
      stopCondition = true;
    else foundTransition = false;
  }
  if (actualState.isStateFinal())
    return true;
  else return false;
}