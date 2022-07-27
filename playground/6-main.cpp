#include "6-template.hpp"
#include <iostream>

int main()
{
    Array<double> a(20);
    for (int i = 0; i < 20; i++)
    {
        a[i] = double(i) + 0.1;
    }

    for (int i = 0; i < 20; i++)
    {
        std::cout << a[i] << std::endl;
    }
}