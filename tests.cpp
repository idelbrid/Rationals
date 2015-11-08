#include "rational.h"
#include <cassert>
void printFrac(Rational frac)
{
	std::cout << frac.getNum() << "/" << frac.getDenom() << std::endl;
}
int run_tests(){
	assert(gcd(5, 50) == 5);
	assert(gcd(10, 62) == 2);
	assert(gcd(0, 10) == 10);
	assert(gcd(0, 0) == 0);
	
	assert(lcm(3, 6) == 6);
	assert(lcm(4, 6) == 12);
	assert(lcm(5, 99) == 99*5);
	
	Rational frac1(5); printFrac(frac1);
	Rational frac2(0,1); printFrac(frac2);
	Rational frac3(8,6); printFrac(frac3);
	printFrac(frac1 + frac2);
	printFrac(frac1 + frac3);
	std::cout << "All tests pass" << std::endl;
	return 0;
}