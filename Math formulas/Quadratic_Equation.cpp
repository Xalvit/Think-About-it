#include <iostream>
#include <math.h>
#include <string>
#include <complex>

void Quadratic_Equation(const double a, const double b, const double c)
{
	// inf = Any number
	// Quadratic equation formula: a * x^2 + b * x + c = 0		||		ax^2 + bx + c = 0
	// Discriminant formula: b^2 - 4 * a * c
	// Root formula: (-b +- sqrt(discriminant))/(a*2)
	// i = sqrt(-1)

	if (a == 0 && b == 0 && c == 0)
	{
		std::cout << "\nRoots:\tAny number.\n";
		return;
	}
	if (a == 0 && b == 0)
	{
		std::cout << "\nRoots don't exist.";
		return;
	}

	if (a == 0) // Equation feature
	{
		double X = -c / b;
		std::cout << "\nRoot:\t" << X;
		return;
	}

	double Discr = pow(b, 2) - (4 * a * c);

	if (Discr < 0) // Equation feature
	{
		std::complex<double> X1(-b/2,sqrt(abs(Discr))/2); // First root
		std::complex<double> X2(-b / 2, -sqrt(abs(Discr)) / 2); // Second root
		std::cout << "First root:\t" << X1 << "i" << std::endl << "Second root:\t" << X2 << "i" << std::endl;
		return;
	}

	if (Discr == 0)  // Equation feature
	{
		double X = -b / (a * 2); // If discriminant = 0, x1 = x2, so there is only one x
		std::cout << "\nRoot:\t" << X;
		return;
	}

	double X1 = (-b - sqrt(Discr)) / (a * 2); // First root
	double X2 = (-b + sqrt(Discr)) / (a * 2); // Second root
	std::cout << "\nFirst root:\t" << X1 << std::endl << "Second root:\t" << X2 << std::endl;
}

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	Quadratic_Equation(a, b, b);
	return 0;
}