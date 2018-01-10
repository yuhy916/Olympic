/*
【题目描述】
哥德巴赫猜想的命题之一是:大于6 的偶数等于两个素数之和。编程将6～100所有偶数表示成两个素数之和。

【输入】
(无）

【输出】
分行输出：

例如:

6=3+3

8=3+5

...

（每个数只拆开一次，请保证第一个加数最小）

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

int main()
{
	for (int i = 6; i <= 100; i=i+2)
	{
		for (int k = 2; k < 100; k++)
		{
			if (isP(k) && isP(i - k))
			{
				cout << i << "=" << k << "+" << i-k << endl;
				break;
			}
		}
	}
	return 0;	
} 
