#include "../include/calculator.h"
#include <iostream>

int main (int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Introduce los números deseados por línea de comandos siguiendo el formato: \n";
    std::cout << "./main [num_base] [num_exponente]\n";
  }
  else if (argc > 3) {
    std::cout << "Introduce los números deseados por línea de comandos siguiendo el formato: \n";
    std::cout << "./main [num_base] [num_exponente]\n";
  }
  else {
    std::cout << argv[1] << "^" << argv[2] << " = ";
    Calculator calc;
    std::cout << calc.pow(std::atoi(argv[1]), std::atoi(argv[2])) << std::endl;
  }
}