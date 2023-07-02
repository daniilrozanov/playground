#include <iostream>

char shift(int i, char sh) { return i << sh; }

int main(int argc, char** argv)
{
  int c;

  std::cin >> c;
  std::cout << shift(c, 2) << std::endl;
  return 0;
}
