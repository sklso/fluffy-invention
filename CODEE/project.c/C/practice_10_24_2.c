#include <stdio.h>


int powerModRec(int b, int n, int m)
{
	if(0==n)
		return 1;
	return b*powerModRec(b, n-1, m)%m;
}

/*“求b的n次方 模m” （非递归实现-->幂模算法）
*/ 
int powerMod(int b, int n, int m)
{
	printf("输入的底数为b=%d，指数为n=%d，模为m=%d\n", b, n, m);
	// a存放计算结果，初始化为1. 
	int a=1;
	int i, k=0, num=n;
	/*计算指数的二进制位数k.
	*/ 
	while(num)
	{
		num = num>>1;
		++k;
	}
	
	// 也可以将指数的二进制用一个数组或队列存放，方便取值.
	for(i=0; i<k; ++i)
	{
		// 取n的二进制的第i位，判断是否为1.
		if((n>>i)&1)
			a = a*b %m;
		b = b*b %m;
	}
	
	return a;
}

int main()
{
	//printf("分别输入底数b，指数n和模m的值：");
	int b, n, m; 
	//scanf("%d%d%d", &b, &n, &m);
	b=12996, n=227, m=37909;
	printf("输入的底数为b=%d，指数为n=%d，模为m=%d\n", b, n, m);
	int result = 0;
	result = powerModRec(b, n, m);
	printf("递归：b^n (mod m) = %d\n", result);

	result = powerMod(b, n, m);
	printf("非递归：b^n (mod m) = %d\n", result);
	return 0;
}

/*
testData: b=12996, n=227, m=37909;
output: result = b^n (mod m) = 7775;
*/