#include <stdio.h>

int main()
{
    double salary, tax;
    double rate, deduction;

    printf("请输入月薪：");
    scanf("%lf", &salary);

    if (salary <= 3500)
    {
        rate = 0;
        deduction = 0;
    }
    else if (salary <= 5000)
    {
        rate = 0.03;
        deduction = 0;
    }
    else if (salary <= 8000)
    {
        rate = 0.15;
        deduction = 250;
    }
    else if (salary <= 12500)
    {
        rate = 0.20;
        deduction = 555;
    }
    else if (salary <= 38500)
    {
        rate = 0.25;
        deduction = 1005;
    }
    else if (salary <= 58500)
    {
        rate = 0.30;
        deduction = 2755;
    }
    else if (salary <= 83500)
    {
        rate = 0.35;
        deduction = 5505;
    }
    else
    {
        rate = 0.45;
        deduction = 13505;
    }

    tax = rate * (salary - 3500) - deduction;

    printf("应交个人所得税为：%.2lf\n", tax);

    return 0;
}                      /*调试时设置断点*/
