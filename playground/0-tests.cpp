#include <iostream>
#include <vector>

int main()
{

   std::pair<std::string, int> strint = std::make_pair("myId2", 2);
   std::pair<std::string, int> strint2 = std::make_pair("myId2", 3);

   strint.swap(strint2);
   std::cout << strint.first << std::endl;
   std::cout << strint.second << std::endl;
   
   std::cout << (strint > strint2) << std::endl;
   std::cout << (strint == strint2) << std::endl;
}