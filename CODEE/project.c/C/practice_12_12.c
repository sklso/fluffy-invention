#include <stdio.h>  
#include <math.h>  
  
int main() {  
    double rate, capital, deposit;  
    int n;  
  
    // 从键盘输入年利率、存款期和存款本金  
    printf("请输入年利率（如2.25表示2.25%%）：");  
    scanf("%lf", &rate);  
    printf("请输入存款期（年）：");  
    scanf("%d", &n);  
    printf("请输入存款本金：");  
    scanf("%lf", &capital);  
  
    // 将年利率转换为小数形式  
    rate /= 100;  
  
    // 使用公式计算本利之和  
    deposit = capital * pow((1 + rate), n);  
  
    // 输出结果，保留两位小数  
    printf("n年后的本利之和为：%.2lf元\n", deposit);  
  
    return 0;  
}