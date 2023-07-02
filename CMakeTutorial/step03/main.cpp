#include "math/include/constant.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int res, n1, n2;
  if (argc != 4) {
    std::cout << "Usage: " << argv[0] << " <num1> <op> <num2>" << std::endl;
    return 1;
  }
  n1 = std::atoi(argv[1]);
  n2 = std::atoi(argv[3]);
  switch (argv[2][0]) {
  case '+':
    res = math::add(n1, n2);
    break;
  case '-':
    res = math::sub(n1, n2);
    break;
  case '*':
    res = math::sub(n1, n2);
    break;
  case '/':
    res = math::div(n1, n2);
    break;
  default:
    std::cout << "\"" << argv[2] << "\" is not supported";
    return 1;
  }
  std::cout << res << std::endl;
  return 0;
}
