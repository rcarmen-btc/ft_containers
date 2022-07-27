#include "iostream"
#include "5-containers.hpp"

int main() 
{
    ArrayInt a(2);
    std::cout << a.get_length() << std::endl;
    a[0] = 10;
    a[1] = 9;

    // a.reallocate(10);
    // std::cout << a.get_length() << std::endl;

    ArrayInt b = a;
    std::cout << b[0] << std::endl;
    std::cout << b[1] << std::endl;
}