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
  explicit Complex(T a_re, T b_im) : a(a_re), b(b_im) {}
  explicit Complex(T par) : a(par), b(T{0}) {}
  ~Complex() {}

  Complex<T> Conjugated() const { return Complex<T>{a, -b}; }
  double constexpr Module() const { return (std::sqrt((a * a) + (b * b))); }
  T GetRe() const { return a; }
  T GetIm() const { return b; }
  double constexpr Angle() const { return std::atan2(this->b,this->a); }
  friend constexpr Complex<T> operator+(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{lhs.a + rhs.a, lhs.b + rhs.b};
  }
  friend constexpr Complex<T> operator^(Complex<T> &lhs, const int &rhs) {
    return Complex<T>{(T)(pow(lhs.Module(),rhs) * std::cos(lhs.Angle() * rhs)),
					  (T)(pow(lhs.Module(),rhs) * std::sin(lhs.Angle() * rhs))};
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
  friend constexpr Complex<T> operator*(const T &rhs, const Complex<T> &lhs) {
    return Complex<T>{lhs.a * rhs, lhs.b * rhs};
  }
  friend constexpr bool operator==(const Complex<T> &lhs,
                                   const Complex<T> &rhs) {
	if (lhs.a == rhs.a && lhs.b == rhs.b && typeid(lhs) == typeid(rhs))
	  return 1;
	else if (lhs.a == rhs.a && lhs.b == rhs.b)
	  return 1;
	return 0;
  }
  friend constexpr Complex<T> operator/(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    if (rhs == Complex<T>(T{0})) {
	  throw std::domain_error("Error: Right operand must not be zero");
	}
    Complex<T> intermediate = rhs * rhs.Conjugated();
    T conj =
        (intermediate.a * intermediate.a + intermediate.b * intermediate.b);
    return Complex<T>{(((lhs.a * rhs.a) + (lhs.b * rhs.b)) / conj),
                      (((lhs.b * rhs.a) - (lhs.a * rhs.b)) / conj)};
  }

  friend constexpr std::ostream &operator<<(std::ostream &a,
                                            const Complex<T> &c) {
    if (c.a == 0 && c.b == 0)
      a << 0;
    else if (c.a == 0)
      a << c.b << "i";
    else if (c.b == 0)
      a << c.a;
    else
      a << c.a << (c.b > 0 ? " + " : " - ") << abs(c.b) << "i";
    return a;
  }
};

#endif
