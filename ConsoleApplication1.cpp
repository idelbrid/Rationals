// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header1.h"
#include <iostream>
#include <cmath>

int64_t gcd(int64_t a, int64_t b)
{
	a = std::abs(a);
	b = std::abs(b);

	if (a < b)
	{
		int64_t temp = a;
		a = b;
		b = temp;
	}

	int64_t r = INT64_MAX;
	while (r != 0)
	{
		int64_t d = a / b; // greatest multiple of b < a
		r = a % b; // remainder of integer division
		a = b;
		b = r;
	}
	return a;
}

Rational::Rational(int64_t num, int64_t denom)
{
	m_num = num;
	m_denom = denom;
	simplified = false;
}

void Rational::simplify(){
	
}
Rational operator+(const Rational &first, const Rational &second){


}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

