#include <iostream>

void display(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
}

int main(){
    int *a,n;
    std::cin >> n;
    a = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] += i;
    }
    display(a, n);
    std::cout << std::endl;
    return 0;
}