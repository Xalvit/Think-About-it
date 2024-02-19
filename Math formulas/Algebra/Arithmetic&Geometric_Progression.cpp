#include <iostream>
#include <math.h>

float Arith_Progress(const float n, const float d, const float a1)
{
	std::cout << "\n" << a1 + d * (n - 1) << "\n";
	return a1 + d * (n - 1);
}
float Arith_Progress_Sum(const float n, const  float a1, const  float d)
{
	std::cout << "\n" << (2 * a1 + d * (n - 1)) * n / 2 << "\n";
	return ((2 * a1 + d * (n - 1)) / 2) * n;
}
float Geo_Progress(const float b1, const  float q, const float n)
{
	std::cout << "\n" << b1 * pow(q, n - 1) << "\n";
	return b1 * pow(q, n - 1);
}
float Geo_Progress_Sum(const float b1, const float n, const float q) // q != 1
{
	if (q != 1)
	{
		std::cout << (b1 * (pow(q, n) - 1)) / (q - 1);
		return (b1 * (pow(q, n) - 1)) / (q - 1);
	}
	else
		std::cout << "ERROR: q = 1";
}
int main()
{

	return 0;
}