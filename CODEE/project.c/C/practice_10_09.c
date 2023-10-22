#include <stdio.h>
int main()
{
    int amount=100;
    int price=0,dick=6;

    printf("请输入金额 （元）：");
    scanf("%d",&price);

    printf("请输入票面");
    scanf("%d",&amount);

    printf("请输入鸡巴长度");
    scanf("%d",&dick);

    int change =amount-price-dick;

    printf("找您%d元。\n",change);
    return 0;
}