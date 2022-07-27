#include "4-timer.hpp"
#include "iostream"


int main()
{
    Timer t;
 
    // Здесь находится код, к которому применяется тайминг
 
    std::cout << "Time elapsed: " << t.elapsed() << '\n';
 
    return 0;
}