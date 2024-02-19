#include <iostream>
#include <math.h>

double Difference_of_arithmetic_progression(const double a2, const double a1)
{
	// a2 = second arithmethic progression number
	// a1 = first arithmethic progression number
	std::cout << "\nArithmetic progression difference:\t" << a2 - a1 << std::endl;
	return a2 - a1;
}

double Arith_Progress(const double n, const double d, const double a1)
{
	std::cout << "\nArith progress number:\t" << a1 + d * (n - 1) << "\n";
	return a1 + d * (n - 1);
}
double Arith_Progress_Sum(const double n, const  double a1, const  double d)
{
	std::cout << "\nArithmetic progress sum:\t" << (2 * a1 + d * (n - 1)) * n / 2 << "\n";
	return ((2 * a1 + d * (n - 1)) / 2) * n;
}
double Geo_Progress(const double b1, const  double q, const double n)
{
	std::cout << "\nGeometric progress:\t" << b1 * pow(q, n - 1) << "\n";
	return b1 * pow(q, n - 1);
}
double Geo_Progress_Sum(const double b1, const double n, const double q) // q != 1
{
	if (q != 1)
	{
		std::cout << "Geometric progression sum:\t" << (b1 * (pow(q, n) - 1)) / (q - 1) << std::endl;
		return (b1 * (pow(q, n) - 1)) / (q - 1);
	}
	else
		std::cout << "ERROR: q = 1";
}
int main()
{
	
	return 0;
}