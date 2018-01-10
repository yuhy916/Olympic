/*
【题目描述】
编程求2～n(n为大于2的正整数)中有多少个素数。

【输入】
输入n(2≤n≤50000)。

【输出】
素数个数。

【输入样例】
10
【输出样例】
4
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

int main()
{
	int n;
	int num = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (isP(i))
		{
			num++;
		}
	}
	cout << num << endl;
	return 0;
}
