/*
【题目描述】
已知



用递归函数求解。

【输入】
第一数是x的值，第二个数是n的值。

【输出】
函数值。

【输入样例】
1 2
【输出样例】
0.40
*/
#include <iostream>
#include <cstdio>
using namespace std;

double f(double x, int n)
{
	if (n == 1)
		return x / (1 + x);
	return x / (n + f(x, n-1));
}

int main()
{
	double x;
	int n;
	while (cin >> x >> n)
	{
		printf("%.2f\n", f(x, n));
	}
	return 0;
}
