#include <iostream>

int main()
{
    int n = 26; // student list number;
    std::string name = "Ekaterina Vakhromeeva";
    std::string email = "vakhromeeva_e_a@student.sechenov.ru";
    double zero = 0.0;
     
    std::cout   << "n=" << n
                << "sizeof(n)=" << sizeof(n)
                << "sizeof(zero)=" << sizeof(zero)
                << "sizeof(n+zero)=" << sizeof(n+zero)
                <<std::endl;
    std::cout   << "Hello world from " << name
                << "with email " << email << "!"
                <<std::endl;
    return 0;
}
