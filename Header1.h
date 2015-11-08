#ifndef HEADERGUARD

#define HEADERGUARD
#include <cstdint>
int64_t gcd(int64_t, int64_t);
class Rational{
private:
	int64_t m_num;
	int64_t m_denom;
	bool simplified;
public:
	Rational(int64_t num, int64_t denom);
	void simplify();
	friend Rational operator+(const Rational &first, const Rational &second);

};

#endif