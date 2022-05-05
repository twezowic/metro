#include <cmath>
#include "Complex.h"

Complex::Complex() noexcept
{
	real = 0.0;
	imaginary = 0.0;
}

Complex::Complex(double real, double imaginary) noexcept
{
	this->real = real;
	this->imaginary = imaginary;
}

double Complex::getReal() const noexcept
{
	return real;
}

double Complex::getImaginary() const noexcept
{
	return imaginary;
}

void Complex::setReal(double const real) noexcept
{
	this->real = real;
}

void Complex::setImaginary(double const imaginary) noexcept
{
	this->imaginary = imaginary;
}

double Complex::magnitude() const noexcept
{
	return sqrt(real * real + imaginary * imaginary);
}

double Complex::direction() const noexcept
{
	return atan2(imaginary, real);
}

Complex Complex::operator+(Complex const& c) const noexcept
{
	return Complex(real + c.getReal(), imaginary + c.getImaginary());
}

Complex Complex::operator-(Complex const& c) const noexcept
{
	return Complex(real - c.getReal(), imaginary - c.getImaginary());
}

Complex Complex::operator+(double v) const noexcept
{
	return Complex(real + v, imaginary);
}

Complex Complex::operator-(double v) const noexcept
{
	return Complex(real - v, imaginary);
}

void Complex::operator+=(Complex const& c) noexcept
{
	real += c.real;
	imaginary += c.imaginary;
}

void Complex::operator+=(double v) noexcept
{
	real += v;
}

void Complex::operator-=(Complex const& c) noexcept
{
	real -= c.real;
	imaginary -= c.imaginary;
}

void Complex::operator-=(double v) noexcept
{
	real -= v;
}

bool Complex::operator==(Complex const& c) const noexcept
{
	return real == c.real && imaginary == c.imaginary;
}

bool Complex::operator==(double v) const noexcept
{
	return real == v && imaginary == 0.0;
}

bool Complex::operator!=(Complex const& c) const noexcept
{
	return !(*this == c);
}

bool Complex::operator!=(double v) const noexcept
{
	return !(*this == v);
}

Complex operator+(double v, Complex const& c)
{
	return Complex(v + c.getReal(), c.getImaginary());
	// return c + v; // an alternative version using the plus operator and the commutation of addition
}

//TODO add a definition of the minus operator that substracts a complex number from a real number (note, the way the operator works is explained by tests)


bool operator==(double v, Complex const& c)
{
	return c == v;
}

//TODO add a declaration of the comparison operator (not equal to) that compares a real number with a complex numbers
