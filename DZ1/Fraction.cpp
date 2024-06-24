#include <iostream>
#include "Fraction.h"

double Fraction:: Imag() const {
	return (double)(m_integer.Im()) + m_fract;
}

Fraction::Fraction() :
	m_fract(0),
	m_integer(0.)
{}

Fraction::Fraction(LongLong p_int, double p_fract) :
	m_integer(p_int),
	m_fract(p_fract)
{}

Fraction::Fraction(double p_value):
	m_integer((long long)p_value)
{
	m_fract = (abs(p_value) - m_integer.Im());
}

Fraction::Fraction(const Fraction& p_val) :
	m_integer(p_val.m_integer),
	m_fract(p_val.m_fract)
{}

Fraction Fraction::operator+(const Fraction& p_val) const {
	double new_fract = m_fract + p_val.m_fract;
	LongLong new_int = m_integer + p_val.m_integer + LongLong(new_fract >= 1);
	if (new_fract >= 1)
		new_fract--;
	return Fraction(new_int, new_fract);
}

Fraction Fraction::operator-(const Fraction& p_val) const {
	double new_fract = m_fract - p_val.m_fract;
	LongLong new_int = m_integer - p_val.m_integer - LongLong(new_fract < 0);
	if (new_fract < 0)
		new_fract++;
	return Fraction(new_int, new_fract);
}

Fraction Fraction:: operator*(const Fraction& p_val) const {
	return Fraction (this->Imag() * p_val.Imag());
}

Fraction Fraction:: operator/(const Fraction& p_val) const {
	return Fraction(this->Imag() / p_val.Imag());
}

bool Fraction::operator<(const Fraction& p_val) const {
	return this->Imag() < p_val.Imag();
}

bool Fraction::operator<=(const Fraction& p_val) const {
	return this->Imag() <= p_val.Imag();
}

bool Fraction::operator>(const Fraction& p_val) const {
	return this->Imag() > p_val.Imag();
}

bool Fraction::operator>=(const Fraction& p_val) const {
	return this->Imag() >= p_val.Imag();
}

//Fraction Fraction::operator+(const Fraction& p_val) {
//	Fraction result((float)(m_integer + p_val.m_integer + ((sign(m_integer) *(float)m_fract + sign(p_val.m_integer) * (float)p_val.m_fract) / 10000)));
//	return result;
//}
//
//Fraction Fraction::operator-(const Fraction& p_val) {
//	Fraction result((float)(m_integer - p_val.m_integer + ((sign(m_integer) * (float)m_fract - sign(p_val.m_integer) * (float)p_val.m_fract) / 10000)));
//	return result;
//}