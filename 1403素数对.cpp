/*
【题目描述】
两个相差为2的素数称为素数对，如5和7，17和19等，本题目要求找出所有两个数均不大于n的素数对。

【输入】
一个正整数n(1≤n≤10000)。

【输出】
所有小于等于n的素数对。每对素数对输出一行，中间用单个空格隔开。若没有找到任何素数对，输出empty。

【输入样例】
100
【输出样例】
3 5
5 7
11 13
17 19
29 31
41 43
59 61
71 73
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
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (isP(i))
			{
				if(isP(i+2) && i+2 <=n)
				{
					cout << i << " " << i+2 << endl;
				}	
			}
		}
	}
	return 0;
}
