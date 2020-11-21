#include "../include/calculator.h"

Calculator::Calculator() {}

Calculator::~Calculator() {}

int Calculator::succesor (int num) {
  return num + 1;
}

int Calculator::zero (int num) {
  return 0;
}

int Calculator::one (int num) {
  return succesor(zero(num));
}

int Calculator::add (int num, int num2) {
  if (num2 == 0)
    return num;
  return succesor(add(num, num2 - 1));
}

int Calculator::product (int num, int num2) {
  if (num2 == 0)
    return zero(num);
  return add(product(num, num2 - 1), num);
}

int Calculator::pow (int num, int num2) {
  if (num2 == 0)
    return one(num);
  return product(pow(num, num2 - 1), num);
}