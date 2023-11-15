#include <stdio.h>
int main(void)
{
    double C, F;   	
    scanf("%lf",&F);      
    C = (F - 32)*5/9;  
    printf("F=%d,C = %.2f\n",F,C); 

    return 0; 
}