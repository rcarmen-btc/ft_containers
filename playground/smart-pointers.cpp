#include <vector>
#include <iostream>

int main() {

    std::vector<int> a;



    std::vector<int>::iterator it = a.begin();
    std::cout << *(it + 2) << std::endl;

} 