/*
【题目描述】
任意输入两个正整数m,n(1<m<n≤5000)，依次输出m到n之间每个数的最大质因子(包括m和n；如果某个数本身是质数，则输出这个数自身)。

【输入】
一行，包含两个正整数m和n，其间以单个空格间隔。

【输出】
一行，每个整数的最大质因子，以逗号间隔。

【输入样例】
5 10
【输出样例】
5,3,7,2,3,5
*/
#include <iostream>
using namespace std;

int isP(int n)
{
	if (n <= 1)
		return 0;
	
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return 0;
	
	return 1;
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		for (int i = m; i <= n; i++)
		{
			if (isP(i))
			{
				cout << i;
			}
			else
			{
				for (int j = i-1; j > 1; j--)
				{
					if (i % j == 0 && isP(j))
					{
						cout << j;
						break;
					}
				}
			}
			if (i != n)
			{
				cout << ',';
			}
		}
		cout << endl;
	}
	return 0;
}
