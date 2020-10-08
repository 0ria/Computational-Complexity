/**
 *  Author: Daniel Oria Martín
 *  Date: 08/10/2020
 *  Assignment: Complejidad Computacional
 *  Task 1: Simulador de autómata con pila
 *  e-mail: alu0101027340@ull.edu.es || danieloriamartin@gmail.com
 *  Location: Escuela Técnica Superior de Ingenieria Informática de La Laguna
 *  Task assignment included in files directory
 * 
 *  This class cleans the comments off from the input file and returns a vector of strings with the clean data
 * 
 */
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Cleaner
{
private:
  std::vector<std::string> data;
public:
  Cleaner(std::ifstream&);
  ~Cleaner();
  std::vector<std::string> clean();
};
