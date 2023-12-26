#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int roll_no;
    std::cout << "Enter your RollNo:"; 
    std::cin >> roll_no;
    std::cout << std::endl;
    std::cout << "Hello " << roll_no << std::endl; 
    printf("Hello %d from printf\n", roll_no);
    return 0;
}