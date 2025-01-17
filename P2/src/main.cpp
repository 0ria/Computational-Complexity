#include <cstring>

#include "../include/Cleaner.h"
#include "../include/TuringMachine.h"

int main(int argc, char* argv[]) {
  std::ifstream f_in;
  std::string inputString;
  std::vector<std::string> noCommentsInput;

  if (argc == 1) {
    std::cout << "Escriba un fichero de texto que contenga los elementos del "
                 "autómata con pila"
              << std::endl;
    std::cout << "./main [ficheroEntrada]" << std::endl;
  }
  else if(argc == 2){
    f_in.open(argv[1]);
    if (!f_in.is_open()) return 1;

    Cleaner cleanData(f_in);
    noCommentsInput = cleanData.clean();

    TuringMachine mt(noCommentsInput);

    std::cout << "Introduzca una cadena para procesar: ";
    std::cin >> inputString;
    mt.newTape(inputString);
    mt.showStats();
    State initialState = mt.getInitialState();
    if (mt.simulate(initialState, 1))
      std::cout << "\nLa cadena se acepta" << std::endl;
    else
      std::cout << "\nLa cadena no se acepta" << std::endl;
  }
}