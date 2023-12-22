#include<stdio.h>
int main(void)
{
int m=0 ,n=0,c=0;

printf("你想要的c是什么？\n");
scanf("%d",&c);
n=-c++;
m=n--;

printf("那么你的n=%d\n",n);
printf("还有你的m=%d\n",m);


return 0;


}