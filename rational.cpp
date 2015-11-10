#include "rational.h"
#include <cmath>

int64_t gcd(int64_t a, int64_t b)
{
	/* Implements Eucliean Algorithm */
	if(a < 0){ a = -a; }
	if(b < 0){ b = -b; }
	
	if (a < b)
	{
		int64_t temp = a;
		a = b;
		b = temp;
	}
	if (a * b == 0)
		return a;
	
	int64_t r = INT64_MAX;
	while (r != 0)
	{
		// int64_t d = a / b; // greatest multiple of b < a
		r = a % b; // remainder of integer division
		a = b;
		b = r;
	}
	return a;
}

int64_t lcm(int64_t a, int64_t b){
	return a * b / gcd(a, b); // may give overflow if a,b very large
}

Rational::Rational(int64_t num, int64_t denom)
	: m_num(num), m_denom(denom), simplified(false)	
{
	if(num == 0)
		m_denom = 1;
	if(denom == 0)
		throw "Divide by zero exception";
}

int64_t Rational::getNum()
{
	return m_num;
}

int64_t Rational::getDenom()
{
	return m_denom;
}

inline bool Rational::isSimplified()
{
	return simplified;
}

void Rational::simplify()
{
	const int64_t g = gcd(m_num, m_denom);
	m_num /= g;
	m_denom /= g;
}

Rational::operator double(){
	return (double)m_num / m_denom;
}

Rational operator+(const Rational &a, const Rational &b){
	const int64_t l = lcm(a.m_denom, b.m_denom);
	
	const int64_t this_new_num = (l / a.m_denom) * a.m_num;
	
	const int64_t other_new_num = (l / b.m_denom) * b.m_num;
	
	return Rational(this_new_num + other_new_num, l);
}

//Rational simplify(const Rational &frac)
//{
//	
//}


//int main(int argc, char* argv[])
//{
//	run_tests();
//	return 0;
//}

