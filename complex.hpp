#include <ostream>
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
template<typename T> class Complex {
private:
  T a;
  T b;
public:
  Complex(T a_re, T b_im) : a(a_re), b(b_im) {};

  ~Complex() {};
  
  static Complex<T> Conjugated(const Complex<T> &c);

  friend constexpr Complex<T> operator+(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{lhs.a + rhs.a, lhs.b + rhs.b};
  }

  friend constexpr Complex<T> operator-(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{lhs.a - rhs.a, lhs.b - rhs.b};
  }

  friend constexpr Complex<T> operator*(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
    return Complex<T>{
      (lhs.a * rhs.a) - (lhs.b * rhs.b),
       (lhs.a * rhs.b) + (lhs.b * rhs.a)
          };
  }

  friend constexpr Complex<T> operator/(const Complex<T> &lhs,
                                        const Complex<T> &rhs) {
	Complex<T> conj = rhs*Conjugated(rhs);
    return Complex<T> {
      (
	   ((lhs.a * rhs.a) + (lhs.b * rhs.b)) / rhs*Complex<T>().Conjugated(rhs)),
	  (((lhs.b * rhs.a) - (lhs.a * rhs.b)) / rhs*Complex<T>().Conjugated(rhs))
	};
  }

  friend constexpr std::ostream &operator<<(std::ostream &a, const Complex<T> &c) {
    if (c.b > 0 && c.a != 0)
      a << c.a << " + " << c.b << "i";
    else if (c.b < 0 && c.a != 0)
      a << c.a << " - " << -c.b << "i";
    if (c.a == 0)
      a << c.b << "i";
    else if (c.b == 0)
      a << c.a;
    return a;
  };
};

#endif
