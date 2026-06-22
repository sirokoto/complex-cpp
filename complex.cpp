#include "complex.hpp"

template <typename T>
Complex<T> Complex<T>::Conjugated(Complex<T> &c) {
	return Complex<T>(c->a, -c->b);
};
