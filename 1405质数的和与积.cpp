/*
【题目描述】
两个质数的和是S，它们的积最大是多少？

【输入】
一个不大于10000的正整数S，为两个质数的和。

【输出】
一个整数，为两个质数的最大乘积。数据保证有解。

【输入样例】
50
【输出样例】
589
*/
#include <iostream>
using namespace std;

int isP(int n)
{
	if (n == 1)
	{
		return 0;
	}
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int s;
	int max;
	while (cin >> s)
	{
		max = 0;
		for (int i = s / 2 + 1; i >= 2; i--)
		{
			if (isP(i) && isP(s - i))
			{
				if (max > i * (s - i))
					break;
				max = i * (s - i);
			}
		}
		cout << max << endl;
	}
	return 0;
}
