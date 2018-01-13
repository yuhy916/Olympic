/*
【题目描述】
用高精度计算出S=1!+2!+3!+…+n!（n≤50）,其中“!”表示阶乘，例如：5!=5*4*3*2*1。

输入正整数N，输出计算结果S。

【输入】
一个正整数N。

【输出】
计算结果S。

【输入样例】
5
【输出样例】
153
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int mul(int *a, int b)
{
	int x = 0;
	for (int i = 1; i <= a[0]; i++)
	{
		a[i] = a[i] * b + x;
		x = a[i] / 10000;
		a[i] %= 10000; 
	}
	if (x > 0)
	{
		a[a[0]+1] = x;
		a[0]++;
	}
	return 0;
}

int fac(int *a, int n)
{
	for (int i = 2; i <= n; i++)
		mul(a, i);
	return 0;
}

int add(int *a, int *b)
{
	int l = a[0] > b[0] ? a[0] : b[0];
	for (int i = 1; i <= l; i++)
	{
		a[i] += b[i];
		a[i+1] += a[i] / 10000;
		a[i] %= 10000; 
	}
	a[0] = a[l+1] > 0 ?  l + 1 : l;
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int s[100000] = {1};
		
		for (int i = 1; i <=n; i++)
		{
			int a[100000] = {1, 1};
			fac(a, i);
			add(s, a);
		}
		
		cout << s[s[0]];
		for (int i = s[0] - 1; i > 0; i--)
			printf("%.4d", s[i]);
		cout << endl;			
	}
	return 0;
}

