/*
【题目描述】
如果一个自然数是素数,且它的数字位置经过对换后仍为素数,则称为绝对素数,例如13。试求出所有二位绝对素数。

【输入】
（无）

【输出】
所有二位绝对素数（由小到大，一个数一行）。

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

int isJP(int n)
{
	int i;
	if (isP(n))
	{
		n = n / 10 + n % 10 * 10;
	
		if(isP(n))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	for (int i = 10; i < 100; i++)
	{
		if (isJP(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}
