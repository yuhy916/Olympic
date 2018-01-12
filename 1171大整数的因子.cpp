/*
【题目描述】
已知正整数k满足2≤k≤9，现给出长度最大为30位的十进制非负整数c，求所有能整除c的k。

【输入】
一个非负整数c，c的位数≤30。

【输出】
若存在满足 c%k == 0 的k，从小到大输出所有这样的k，相邻两个数之间用单个空格隔开；若没有这样的k，则输出"none"。

【输入样例】
30
【输出样例】
2 3 5 6
*/
#include <iostream>
#include <cstring>
using namespace std;

int init(int *a)
{
	string s;
	cin >> s;
	a[0] = s.length();
	for (int i = 1; i <= a[0]; i++)
		a[i] = s[i-1] - '0';
	return 0;
}

int mod(int *a, int b, int *c)
{
	int x = 0;
	for(int i = 1; i <= a[0]; i++)
	{
		c[i] = (10 * x + a[i]) / b;
		x = (10 * x + a[i]) % b;
	}
	c[0] = a[0];
	while (c[c[0]] == 0 && c[0] > 1)
		c[0]--;
	return x;
}

int main()
{
	int a[32] = {0}, c[32] = {0}, t[10] = {0}, n = 0;
	init(a);
	for (int k = 2; k <= 9; k++)
	{
		memset(c, 0, sizeof(c));
		if (mod(a, k, c) == 0)
			t[n++] = k;
	}
	if (n == 0)
		cout << "none"; 
	for (int i = 0; i < n; i++)
	{
		cout << t[i];
		if (i < n-1)
			cout << " ";
	}
	cout << endl;
	return 0;
}
