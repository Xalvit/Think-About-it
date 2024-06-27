#include <iostream>
#include <math.h>
#include <Windows.h>

class Calculator
{
public:
    double x = 0;
    double y = 0;
    char symb = ' ';
    bool hasY = true;
    Calculator();

    /*!*/void Fac()
    {
        double temp = 1;
        for (int i = 1; i < x; i++)
        {
            temp *= i;
        }
        std::cout << temp << std::endl;
    }
    /*+*/void Sum()
    {
        std::cout << x + y << std::endl;
    }
    /*-*/void Sub()
    {
        std::cout << x - y << std::endl;
    }
    /*^*/void Pow()
    {
        std::cout << pow(x, y) << std::endl;
    }
    /*v*/void Sqrt()
    {
        std::cout << sqrt(x) << std::endl;
    }
    /*/*/void Div()
    {
        if (y != 0)
            std::cout << x/y << std::endl;
        else
            std::cout << "ERROR:y=0";
    }
    /***/void Mult()
    {
        std::cout << x*y << std::endl;
    }

};

Calculator::Calculator()
{
    std::cin >> x >> symb;
    if (symb == 'v')
    {
        hasY = false;
        Sqrt();
    }
    if (symb == '!')
    {
        hasY = false;
        Fac();
    }
    if (hasY)
    { 
        std::cin >> y;
    }

    switch (symb)
    {
    case '+':
        Sum();
        break;
    case '-':
        Sub();
        break;
    case '*':
        Mult();
        break;
    case '/':
        Div();
        break;
    case '!':
        Fac();
        break;
    case 'v':
        Sqrt();
        break;
    case '^':
        Pow();
        break;
    default:
        break;
    }
}

int main()
{
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 500, 350, 550, 150, 0);

    Calculator poj;

    system("pause");
    return 0;
}