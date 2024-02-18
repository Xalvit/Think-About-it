#include <iostream>
#include <math.h>
#include <string>

std::string Quadratic_Equation(const double a, const double b, const double c)
{
	// inf = Any number
	// Quadratic equation formula: a * x^2 + b * x + c = 0		||		ax^2 + bx + c = 0
	// Discriminant formula: b^2 - 4 * a * c
	// Root formula: (-b +- sqrt(discriminant))/(a*2)

	if (a == 0 && b == 0 && c == 0)
	{
		std::cout << "\nRoots:\tAny number.\n";
		return "Any number";
	}
	if (a == 0 && b == 0)
	{
		std::cout << "\nRoots don't exist.";
		return "Roots don't exist.";
	}

	if (a == 0) // Equation feature
	{
		double X = -c / b;
		std::cout << "\nRoot:\t" << X;
		return std::to_string(X);
	}

	double Discr = pow(b, 2) - (4 * a * c);

	if (Discr < 0) // Equation feature
	{
		std::cout << "\nRoots don't exist.\n";
		return "Roots don't exist."; // Discriminant can't be lower than 0, because sqrt(-x) doesn't exist
	}

	if (Discr == 0)  // Equation feature
	{
		double X = -b / (a * 2); // If discriminant = 0, x1 = x2, so there is only one x
		std::cout << "\nRoot:\t" << X;
		return std::to_string(X);
	}

	double X1 = (-b - sqrt(Discr)) / (a * 2); // First root
	double X2 = (-b + sqrt(Discr)) / (a * 2); // Second root
	std::cout << "\nFirst root:\t" << X1 << std::endl << "Second root:\t" << X2 << std::endl;
	return std::to_string(X1) + " ; " + std::to_string(X2);
}

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