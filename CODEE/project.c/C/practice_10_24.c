#include <stdio.h>
int main()
{ 
  int total,number;float average;

  printf("请输入总数：");
  scanf("%d",&total);

  printf("请输入人数：");
  scanf("%d",&number);

  average=(float)total/number;

  printf("平均数是%d。 \n",average);
  return 0;
}