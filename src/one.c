#include <stdio.h>

int fun(int n);

int main() {
    int a = 0;
    int* p = &a;
    int hi = fun(10);
    printf("%d %p", --hi, p);
    
}

int fun(int n) {
    return (n++);
}
