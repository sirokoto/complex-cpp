#include <iostream>
#include "complex.hpp"

int main() {
  Complex<int> a(-4,1);
  Complex<int> b(4, 5);  
  //std::cout << a/b << std::endl;
  std::cout << a << Complex<int>::Conjugated(a) << std::endl;
  return 0;
}
