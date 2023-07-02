#include <iostream>

#ifdef USE_LIBMATH
#define ADD(x, y)                    \
  std::cerr << "[Add]" << std::endl; \
  return ((x) + (y))
#define SUB(x, y)                    \
  std::cerr << "[Sub]" << std::endl; \
  return ((x) - (y))
#define MUL(x, y)                    \
  std::cerr << "[Mul]" << std::endl; \
  return ((x) * (y))
#define DIV(x, y)                    \
  std::cerr << "[Div]" << std::endl; \
  return ((x) / (y))
#else
#define ADD(x, y) return ((x) + (y))
#define SUB(x, y) return ((x) - (y))
#define MUL(x, y) return ((x) * (y))
#define DIV(x, y) return ((x) / (y))
#endif

namespace math {
int add(int l, int r) { ADD(l, r); }
int mul(int l, int r) { MUL(l, r); }
int div(int l, int r) { DIV(l, r); }
int sub(int l, int r) { SUB(l, r); }

}  // namespace math
