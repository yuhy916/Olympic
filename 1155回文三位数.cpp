/*
【题目描述】
如果一个数从左边读和从右边读都是同一个数，就称为回文数。例如6886就是一个回文数，求出所有的既是回文数又是素数的三位数。

【输入】
(无）

【输出】
所有的既是回文数又是素数的三位数。一个数一行。

【输入样例】
（无）
【输出样例】
（无）
*/
#include <iostream>
using namespace std;

int isP(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int isHW(int n)
{
	return n / 100 == n % 10 ? 1 : 0;
}

int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (isP(i) && isHW(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}
