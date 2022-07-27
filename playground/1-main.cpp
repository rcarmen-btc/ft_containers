#include "1-date-class.hpp"

int main() {

    const DateClass my_birthday;
    DateClass my_twin(1, 3, 4);
    
    my_twin.print();

    // my_birthday.set_date(23, 1, 2003);
    my_birthday.print();

    my_twin.copy(my_birthday);
    my_twin.print();

}