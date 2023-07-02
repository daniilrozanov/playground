#include "config.hpp"
#include <cstdlib>
#include <iostream>
#include <string_view>

#define STRING(s) #s

void version()
{
#ifdef ex1_VERSION_MAJOR
#ifdef ex1_VERSION_MINOR
  std::cout << ex1_VERSION_MAJOR << "." << ex1_VERSION_MINOR << std::endl;
#endif
#else
  std::cout << "Version not described" << std::endl;
#endif
}

int main(int argc, char** argv)
{
  version();
  if (argc < 2)
  {
    std::cout << "enter number as argument: " << argv[0] << " <number>" << std::endl;
    return 1;
  }
  int n = std::atoi(argv[1]);
  std::cout << n * n << std::endl;
  return 0;
}
