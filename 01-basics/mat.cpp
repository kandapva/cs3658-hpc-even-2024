#include <iostream>

void display(int *a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << *(a++) << "\t";
        }
        std::cout << std::endl;
    }
}

int main(){
    int a[10][10];
    int *b;
    for(int i=0;i<10;i++){
        for (int j = 0; j < 10; j++){
            std::cin >> a[i][j];
            a[i][j] += i*j;
        }
    }
    b = &a[0][0];
    display(b,10);
    std::cout << std::endl;
    return 0;
}