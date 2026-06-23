#include "complex.hpp"
#include <iostream>

void ManuallCalculation(double real, double imag) {
  int n = 2; // Exponent
  double r = sqrt((real * real) + (imag * imag)); // Module or Distance or Hypotenuse
  double ang = std::atan(imag / real); // Angle between Complex number as Vector and Ox;
  double RealTrigPart = (r * r) * cos(ang * n); // Trigonometric Real Part of Complex number
  double ImagTrigPart = (r * r) * sin(ang * n); // Trigonometric Imaginary Part of Complex number
  // Check for output
  if (ImagTrigPart > 0 && RealTrigPart != 0)
    std::cout << RealTrigPart << " + " << ImagTrigPart << "i";
  else if (ImagTrigPart < 0 && RealTrigPart != 0)
    std::cout << RealTrigPart << " - " << -ImagTrigPart << "i";
  if (RealTrigPart == 0)
    std::cout << ImagTrigPart << "i";
  else if (ImagTrigPart == 0)
    std::cout << RealTrigPart;
  std::cout << std::endl;
}

int main() {
  Complex<double> a(-4, 1);
  Complex<double> b(0);
  double RealPart = -4;
  double ImagPart = 1;
  std::cout << "Manually calculated:\n";
  ManuallCalculation(RealPart, ImagPart);
  std::cout << "My library:\n";
  std::cout << (a ^ 2) << std::endl;
  std::cout << b << std::endl;
  return 0;
}
