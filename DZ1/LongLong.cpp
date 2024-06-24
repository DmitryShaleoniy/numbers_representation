#include <Windows.h>
#include <string>
#include "LongLong.h"
#define MAX 0xFFFFFFFF


LongLong::LongLong():
	m_Hiword(0),
	m_Loword(0)
{}

long long LongLong::Im() const {
	return (static_cast<long long>(m_Hiword) << 32) | m_Loword;
	//return (((long long)(this->m_Hiword) << 32) + (long long)(this->m_Loword));
}

LongLong::LongLong(long long p_num) {
	m_Hiword = (p_num >> 32);
	m_Loword = (p_num & MAX);
}

LongLong::LongLong(long p_Hiword, unsigned long p_Loword):
	m_Hiword(p_Hiword),
	m_Loword(p_Loword)
{}

LongLong LongLong::operator+(const LongLong& p_val) const {
	unsigned long new_lo = m_Loword + p_val.m_Loword;
	long new_hi = m_Hiword + p_val.m_Hiword + (new_lo < m_Loword); //учет переноса
	if (new_hi < m_Hiword) {
		return LongLong(0, 0);
	}
	return LongLong(new_hi, new_lo);
}

LongLong LongLong::operator-(const LongLong& p_val) const {
	unsigned long new_lo = m_Loword - p_val.m_Loword;
	long new_hi = m_Hiword - p_val.m_Hiword - (new_lo > m_Loword); // Учет заема
	if (new_hi > m_Hiword) {
		return LongLong(0, 0);
	}
	return LongLong(new_hi, new_lo);
}

LongLong LongLong::operator*(const LongLong& p_val) const {
	/*unsigned long lo_lo = m_Loword * p_val.m_Loword;
	unsigned long lo_hi = m_Loword * p_val.m_Hiword;
	unsigned long hi_lo = m_Hiword * p_val.m_Loword;
	unsigned long hi_hi = m_Hiword * p_val.m_Hiword;*/

	unsigned long new_lo = (m_Loword * p_val.m_Loword) & MAX;
	long new_hi = (((long long)m_Loword * (long long)p_val.m_Loword)>>32 + (m_Loword * p_val.m_Hiword)&MAX + (m_Hiword * p_val.m_Loword)&MAX) & MAX;
	return LongLong(new_hi, new_lo);
}

LongLong LongLong::operator/(const LongLong& p_val) const {
	return LongLong(this->Im()/p_val.Im());
}

long long LongLong::ToOrigin() {
	return (m_Hiword << 32) | m_Loword;
}