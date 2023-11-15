# include <stdio.h> 
# include <math.h>
int main(void)
{   double deposit,benji,rate;
    double n;
    rate=0.0225;


    printf("请输入存款（元）：");
    scanf("%d\n",&benji);

    printf("请输入存款期（年）；");
    scanf("%d\n",&n);

    deposit=benji*(1+rate)^n;
    printf("本息和=%d\n",deposit);


    return 0;
}