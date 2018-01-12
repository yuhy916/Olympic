/*
【题目描述】
求10000以内n的阶乘。

【输入】
只有一行输入，整数n（0≤n≤10000）。

【输出】
一行，即n!的值。

【输入样例】
4
【输出样例】
24
*/
#include <iostream>
#include <cstring>
using namespace std;

int mul(int *a, int *b, int *c)
{
	int x = 0;
	for (int i = 1; i <= a[0]; i++)
	{
		for (int j = 1; j <= b[0]; j++)
		{
			c[i+j-1] = a[i] * b[j] + x + c[i+j-1];
			x = c[i+j-1] / 10;
			c[i+j-1] %= 10; 
		}
		c[i+b[0]] = x;
	}
	c[0] = a[0] + b[0];
	while (c[c[0]] == 0 && c[0] > 1)
		c[0]--;
}

int toB(int *a, int n)
{
	int num = 0;
	while (n)
	{
		a[++num] = n % 10;
		n /= 10;
	}
	a[0] = num+1;
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int a[100000] = {0}, b[10] = {0}, c[100000] = {0};
		a[0] = 1;
		a[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			memset(c, 0, sizeof(c));
			toB(b, i);
			mul(a, b, c);
			for (int j = 0; j <= c[0]; j++)
				a[j] = c[j];
		}
			
		for (int i = a[0]; i > 0; i--)
			cout << a[i];
		cout << endl;
	}
	return 0;
}
