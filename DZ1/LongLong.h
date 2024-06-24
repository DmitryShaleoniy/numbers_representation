#ifndef LONGLONG_H
#define LONGLONG_H

class LongLong {
private:
	long m_Hiword;
	unsigned long m_Loword;
public:
	LongLong();
	explicit LongLong(long long p_num);
	explicit LongLong(long p_Hiword, unsigned long p_Loword);
	long long ToOrigin();
	LongLong operator+(const LongLong& p_val) const;
	LongLong operator-(const LongLong& p_val) const;
	LongLong operator*(const LongLong& p_val) const;
	LongLong operator/(const LongLong& p_val) const;
	long long Im() const;
};

#endif
