#ifndef RATIONAL

#define RATIONAL
#include <iostream>
#include <cstdint>
int64_t gcd(int64_t, int64_t);
int64_t lcm(int64_t, int64_t);
class Rational{
private:
	int64_t m_num;
	int64_t m_denom;
	bool simplified;
public:
	Rational(int64_t num, int64_t denom=1);
	int64_t getNum();
	int64_t getDenom();
	bool isSimplified();
	void simplify();
	operator double();
	// operator int();
	friend Rational operator+(const Rational &first, const Rational &second);
	friend Rational simplify(const Rational &frac);
};

int run_tests();
#endif