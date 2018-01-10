/*
求正整数2和n之间的完全数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 992     通过数: 591 
【题目描述】
求正整数2和n之间的完全数(一行一个数)。

完全数：因子之和等于它本身的自然数，如6=1+2+3

【输入】
输入n。

【输出】
一行一个数,按由小到大的顺序。

【输入样例】
7
【输出样例】
6
*/
#include <iostream>
using namespace std;

int isWQ(int n)
{
	int s = 1;
	
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i != n / i)
			{
				s += n / i;
			}
			s += i;
		}
	}
	if (s == n) 
	{
		return 1;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if(isWQ(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}
