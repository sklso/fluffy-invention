# include <stdio.h> 
int main(void)
{   double BMI,w,h;
    printf("请分别输入您的体重(kg)与身高(cm):\n");
    scanf("%d %d",&w,&h);
    BMI=w/h/h;



if (BMI>=20)
{
        printf("您的指数正常\n");
        return 0;
}
   


else
{
        printf("您的指数不正常\n");
        return 0;
} 
    return 0;
}