#ifndef FRACTION_H
#define FRACTION_H

#include "LongLong.h"

class Fraction {
private:
	LongLong m_integer;
	double m_fract;
public:
	Fraction();
	explicit Fraction(double p_value);
	Fraction(LongLong p_int, double p_fract);
	Fraction(const Fraction& p_val);
	//Fraction& operator=(const Fraction& p_val);
	Fraction operator+(const Fraction& p_val) const;
	Fraction operator-(const Fraction& p_val) const;
	Fraction operator*(const Fraction& p_val) const;
	Fraction operator/(const Fraction& p_val) const;

	bool operator<(const Fraction& p_val) const;
	bool operator<=(const Fraction& p_val) const;
	bool operator>(const Fraction& p_val) const;
	bool operator>=(const Fraction& p_val) const;
	double Imag () const;
};

#endif // !FRACTION_H