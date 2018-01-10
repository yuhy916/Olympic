/*
【题目描述】
自然数a的因子是指能整除a的所有自然数，但不含a本身。例如12的因子为：1,2,3,4,6。若自然数a的因子之和为b，而且b的因子之和又等于a，则称a,b为一对“亲和数” 。求最小的一对亲和数(a<>b)。

【输入】
(无）

【输出】
1行，分别为a和b(a<b)。

【输入样例】
（无）
【输出样例】
（无）
*/
#include <iostream>
using namespace std;

int sumY(int n)
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
	return s;
}

int main()
{
	int a, b;
	for (a = 2; ; a++)
	{
		b = sumY(a);
		if (sumY(b) == a && b > a)
		{
			break;
		}
	}
	cout << a << " " << b << endl;
	
	return 0;
}
