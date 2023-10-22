#include <stdio.h>
int  mian()
{
    int a;

    int b;

    int c;

    printf("请输入你的三围：");

    scanf("%d %d %d",&a,&b,&c);
    printf("%d+%d+%d=%d\n",a,b,c,a+b+c);

    return 0;
}