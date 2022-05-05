#pragma once
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex() noexcept;
	Complex(double real, double imaginary) noexcept;
	double getReal() const noexcept;
	double getImaginary() const noexcept;
	void setReal(double const real) noexcept;
	void setImaginary(double const imaginary) noexcept;
	double magnitude() const noexcept;
	double direction() const noexcept;

	Complex operator+(Complex const& c) const noexcept;
	Complex operator-(Complex const& c) const noexcept;
	Complex operator+(double v) const noexcept;
	Complex operator-(double v) const noexcept;

	void operator+=(Complex const& c) noexcept;
	void operator+=(double v) noexcept;
	void operator-=(Complex const& c) noexcept;
	void operator-=(double v) noexcept;

	bool operator==(Complex const& c) const noexcept;
	bool operator==(double v) const noexcept;
	bool operator!=(Complex const& c) const noexcept;
	bool operator!=(double v) const noexcept;
};

Complex operator+(double v, Complex const& c);

//TODO add a declaration of the minus operator that substracts a complex number from a real number (note, the way the operator works is explained by tests)


bool operator==(double v, Complex const& c);

//TODO add a declaration of the comparison operator (not equal to) that compares a real number with a complex numbers
