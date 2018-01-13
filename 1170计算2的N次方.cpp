/*
【题目描述】
任意给定一个正整数N(N≤100)，计算2的n次方的值。

【输入】
输入一个正整数N。

【输出】
输出2的N次方的值。

【输入样例】
5
【输出样例】
32
*/
#include <iostream>
#include <cstring>
using namespace std;

int mul(int *a)
{
	int x = 0;
	for (int i = 1; i <= a[0]; i++)
	{
		a[i] = a[i] * 2 + x;
		x = a[i] / 10;
		a[i] %= 10; 
	}
	if (x > 0)
	{
		a[a[0]+1] = x;
		a[0]++;
	}
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int a[10000] = {0};
		a[0] = 1;
		a[1] = 1;
		for (int i = 0; i < n; i++)
			mul(a);
		for (int i = a[0]; i > 0; i--)
			cout << a[i];
		cout << endl;
	}
	return 0;
}

