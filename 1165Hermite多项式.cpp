/*
【题目描述】
用递归的方法求Hermite多项式的值



对给定的x和正整数n，求多项式的值。

【输入】
给定的n和正整数x。

【输出】
多项式的值。

【输入样例】
1 2
【输出样例】
4.00
*/
#include <iostream>
#include <cstdio>
using namespace std;

double h(int n, double x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 2 * x;
	if (n > 1)
		return 2 * x * h(n-1, x) - 2 * (n - 1) * h(n-2, x);
}

int main()
{
	int n;
	double x;
	while (cin >> n >> x)
	{
		printf("%.2lf\n", h(n, x));
	}
	return 0;
}
