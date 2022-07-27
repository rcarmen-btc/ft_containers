#include <iostream>


void test_by_point(int const *a)
{
    int b = 100;
    std::cout << *a << std::endl;
    // *a = 11;
    a = &b;
    std::cout << *a << std::endl;
}

void test_by_ref(int &a)
{
    std::cout << a << std::endl;
    a = 11;
    std::cout << a << std::endl;
}

void test_by_val(int a)
{
    std::cout << a << std::endl;
    a = 11;
    std::cout << a << std::endl;
}

int main()
{
    int a = 10;
    std::cout << "--- In main: " << a << std::endl;
    test_by_val(a);

    a = 10;
    std::cout << ">> In main: " << a << std::endl;
    test_by_ref(a);
    std::cout << ">> In main: " << a << std::endl;

    a = 10;
    test_by_point(&a);
    std::cout << ">> In main: " << a << std::endl;
}