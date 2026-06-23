#include <cmath>
#include <cstdlib>
#include <ostream>
#include <stdexcept>
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

template <typename T> class Complex {
private:
  T a;
  T b;

public:
  Complex(T a_re, T b_im) : a(a_re), b(b_im) {};
  Complex(T par) : a(par), b(par) {};
  ~Complex() {};

  T mod = this->Module();
  T ang = this->GetAngle();

  Complex<T> Conjugated() const { return Complex<T>{a, -b}; }
  T Module() const { return (T)(std::abs(std::sqrt((a * a) + (b * b)))); }
  T GetRe() const { return a; }
  T GetIm() const { return b; }
  T GetAngle() const { return (T)std::atan(this->b / this->a); };
  friend constexpr Complex<T> operator+(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{lhs.a + rhs.a, lhs.b + rhs.b};
  }
  friend constexpr Complex<T> operator^(Complex<T> &lhs, const int &rhs) {
    if (lhs.a == 0) {
	  // TODO: Not implemented yet!
	  throw std::logic_error("Operation is not implemented.");
	}
    return Complex<T>{(lhs.mod * lhs.mod) * std::cos(lhs.ang * rhs),
                      (lhs.mod * lhs.mod) * std::sin(lhs.ang * rhs)};
  }

  friend constexpr Complex<T> operator-(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{lhs.a - rhs.a, lhs.b - rhs.b};
  }

  friend constexpr Complex<T> operator*(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{(lhs.a * rhs.a) - (lhs.b * rhs.b),
                      (lhs.a * rhs.b) + (lhs.b * rhs.a)};
  }
  friend constexpr Complex<T> operator*(const Complex<T> &lhs, const T &rhs) {
    return Complex<T>{lhs.a * rhs, lhs.b * rhs};
  }

  friend constexpr Complex<T> operator/(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    Complex<T> intermediate = rhs * rhs.Conjugated();
    T conj =
        (intermediate.a * intermediate.a + intermediate.b * intermediate.b);
    return Complex<T>{(((lhs.a * rhs.a) + (lhs.b * rhs.b)) / conj),
                      (((lhs.b * rhs.a) - (lhs.a * rhs.b)) / conj)};
  }

  friend constexpr std::ostream &operator<<(std::ostream &a,
                                            const Complex<T> &c) {
    if (c.b > 0 && c.a != 0)
      a << c.a << " + " << c.b << "i";
    else if (c.b < 0 && c.a != 0)
      a << c.a << " - " << -c.b << "i";
    if (c.a == 0)
      a << c.b << "i";
    else if (c.b == 0)
      a << c.a;
    else if (c.a == 0 && c.b == 0)
	  a << 0;
    return a;
  };
};

#endif
