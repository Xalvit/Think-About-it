#include <iostream>

void Multi_Form()
{
	std::cout << "\nSquare of sum:\t\t(a+b)^2 = a^2 + 2ab + b^2\n";
	std::cout << "Square of difference:\t(a-b)^2 = a^2 - 2ab + b^2\n";
	std::cout << "Diference of squares:\t a^2 - b^2 = (a-b)(a+b)\n\n";
	std::cout << "Sum of cubes:\t\ta^3 + b^3 = (a+b)(a^2-ab+b^2)\n";
	std::cout << "Diference of cubes:\ta^3 - b^3 = (a-b)(a^2+ab+b^2)\n";
	std::cout << "Cube of sum:\t\t(a+b)^3 = a^3 + 3a^b + 3b^2a + b^3\n";
	std::cout << "Cube of diference:\t(a-b)^3 = a^3 - 3a^b + 3b^2a - b^3\n";
}

int main()
{

	return 0;
}