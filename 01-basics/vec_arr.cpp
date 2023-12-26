#include <iostream>

void display(int *a, int n){
    for (int i = 0; i < n; i++){
        std::cout << a[i] << "\t";
    }
}

int main(){
    int a[10];
    int *b;
    for(int i=0;i<10;i++){
        std::cin >> a[i];
        a[i] += i;
    }
    b = &a[0];
    display(b,10);
    std::cout << std::endl;
    return 0;
}