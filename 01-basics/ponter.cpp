#include <iostream>

int main(){
    int b = 10;
    int *a;
    a = &b;
    std::cout << "Address - " << a << " Value - "<<  *a << std::endl;
    (*a)++;
    std::cout << "Address - " << a << " Value - " << *a << std::endl;
    a++;
    std::cout << "Address - " << a << " Value - " << *a << std::endl;

    int c[] = {1,2};
    a = &c[0];
    std::cout << "Address - " << a << " Value - " << *a << std::endl;
    (*a)++;
    std::cout << "Address - " << a << " Value - " << *a << std::endl;
    a++;
    std::cout << "Address - " << a << " Value - " << *a << std::endl;

    return 0;
}