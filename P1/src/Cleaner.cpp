#include "../include/Cleaner.h"

Cleaner::Cleaner(std::ifstream& inputFile) {
  std::string auxStr;
  while (getline(inputFile, auxStr))
    data.push_back(auxStr);
}

Cleaner::~Cleaner() {}

std::vector<std::string> Cleaner::clean() {
  int aux;
  std::vector<std::string> finalVector;
  for (auto it : data) {
    aux = it.find('#');
    if (aux == std::string::npos) {
      finalVector.push_back(it);
    }
  }
  return finalVector;
}
