#include <iostream>
#include "Calculator.h"

int Calculator::m_counter = 0;

Calculator::Calculator ():
	m_val(0)
{
	m_counter++;
}

Calculator::Calculator(double p_val):
	m_val(p_val)
{
	m_counter++;
}

Calculator::Calculator(const Fraction& p_val) :
	m_val(p_val)
{
	m_counter++;
}

double Calculator::Imag() const {
	return m_val.Imag();
}

Calculator& Calculator::operator=(double p_val) {
	m_val = Fraction(p_val);
	return *this;
}

Calculator Calculator::operator+(const Calculator& p_val) const {
	return Calculator(this->m_val + p_val.m_val);
}

Calculator Calculator::operator-(const Calculator& p_val) const {
	return Calculator(this->m_val - p_val.m_val);
}

Calculator Calculator::operator*(const Calculator& p_val) const {
	return Calculator(this->m_val * p_val.m_val);
}

Calculator Calculator::operator/(const Calculator& p_val) const {
	return Calculator(this->m_val / p_val.m_val);
}

Calculator::~Calculator() {
	m_counter--;
}