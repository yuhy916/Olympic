/*
【题目描述】
根据公式：

arctanx(x)=x?x33+x55?x77+...arctanx(x)=x?x33+x55?x77+...和π=6arctanx(13√)π=6arctanx(13)
定义函数arctanx(x)，求当最后一项小于10?610?6时π的值。

【输入】
（无）

【输出】
π的值。保留到小数点后10位。

【输入样例】
（无）
【输出样例】
（无）
*/
#include <cstdio>
#include <cmath>

double arctanx(double x)
{
	double sum = 0;
	double n;
	
	for (int i = 1; ; i++)
	{
		n = pow(-1, i + 1) * pow(x, 2 * i - 1) / (2 * i - 1);
		
		if (fabs(n) < 1e-6)
		{
			break;
		}
		sum += n; // 最后一项为什么不加 
	}
	return sum;
}

int main()
{
	double PI = 6.0 * arctanx(1 / sqrt(3));
	printf("%.10lf\n", PI);
	return 0;
}
