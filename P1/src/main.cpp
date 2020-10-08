#include <cstring>
#include <fstream>
#include <iostream>

#include "../include/Cleaner.h"
#include "../include/FSA.h"

int main(int argc, char* argv[]) {
  std::ifstream f_in;
  std::ofstream f_out;
  std::vector<std::string> noCommentsInput;

  if (argc == 1) {
    std::cout << "Escriba un fichero de texto que contenga los elementos del "
                 "autómata con pila"
              << std::endl;
    std::cout << "./main [ficheroEntrada]" << std::endl;
  } else {
    if (argc == 2) {
      f_in.open(argv[1]);
      if (!f_in.is_open()) return 1;

      Cleaner cleanData(f_in);
      noCommentsInput = cleanData.clean();

      FSA Automata(noCommentsInput);

      /*
      for (auto it : noCommentsInput) {
      std::cout << it << std::endl;
      }
      */

      f_in.close();
    }
  }
}