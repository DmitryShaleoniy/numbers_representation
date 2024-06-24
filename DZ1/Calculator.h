#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Fraction.h"

class Calculator {
	Fraction m_val;
public:
	static int m_counter;
	Calculator();
	explicit Calculator(double p_val);
	explicit Calculator(const Fraction& p_val);

	Calculator& operator=(double p_val) ;
	Calculator operator+(const Calculator& p_val) const;
	Calculator operator-(const Calculator& p_val) const;
	Calculator operator*(const Calculator& p_val) const;
	Calculator operator/(const Calculator& p_val) const;
	double Imag() const;


	~Calculator();
};

#endif