#include <stdio.h>  
  
double fact(int n);  
  
int main(void) {      
    int i;  
    double sum = 0;   
    for (i = 1 ; i < 10; i++)   
        sum = sum + fact(i);              /*设置断点*/  
    printf("1!+2!+…+10! = %f\n", sum);   
    return 0;  
}  
  
double fact(int n) {  
    int i;  
    double result = 1;  
    for (i = 1 ; i <=n; i++)   
        result = result * i;  
    return result;  
}