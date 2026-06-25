#include "complex.hpp"
#include <iostream>

int main() {
  
  std::cout << Complex<int>(0) << std::endl;
  std::cout << Complex<int>(1) << std::endl;
  std::cout << Complex<int>(1,1) << std::endl;
  std::cout << Complex<int>(1,-1) << std::endl;
  std::cout << Complex<int>(-1,1) << std::endl;
  std::cout << Complex<int>(-1,-1) << std::endl;
   return 0;
}
