#include <stdio.h>  
  
int main() {  
    int a[6][6], i, j, m, n, sum;  
    printf("Enter the number of integers: ");  
    scanf("%d", &m);  
    printf("Enter the number of rows and columns: ");  
    scanf("%d", &n);  
    printf("Enter the array:\n");  
    for (i = 0; i < m; i++) {  
        for (j = 0; j < n; j++) {  
            scanf("%d", &a[i][j]);  
        }  
    }  
    for (i = 0; i < m; i++) {  
        sum = 0;  
        for (j = 0; j < n; j++) {  
            sum += a[i][j];  
        }  
        printf("Sum of row %d is %d\n", i, sum);  
    }  
    return 0;  
}