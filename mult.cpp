#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int main(int ac, char **av) {
    if (ac != 2)
        return (-1);
    
    int num = std::atoi(av[1]);
    int reserve_num = num;
    std::cout << num << std::endl;
    std::vector<int> mults;


    while (num != 1) {
        for (int i = 2; i < 6; i++) {
            while (num % i == 0) {
                num /= i;
                std::cout << "-" << num << " " << i << "-"  << num % i << std::endl;
                mults.push_back(i);
            }
            if (num == 1)
                break;
        }
        if (num == reserve_num)
            mults.clear();
            break;
    }
    std::cout << "-----" << std::endl;
    for (int i = 0; i < mults.size(); i++) {
        std::cout << mults[i] << std::endl;
    }

    std::cout << num << std::endl;

}