/*
【题目描述】
输入两个整数X和Y，输出两者之间的素数个数（包括X和Y）。

【输入】
两个整数X和Y（1 ≤ X,Y ≤ 105）。

【输出】
输出一个整数，表示X，Y之间的素数个数（包括X和Y）。

【输入样例】
1 100
【输出样例】
25
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
	int x, y;
	while(cin >> x >> y)
	{
		int num = 0;
		for (int i = x; i <= y; i++)
		{
			if (isP(i))
			{
				num++;
			}
		}
		cout << num << endl;
	}
	return 0;
}
