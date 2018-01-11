/*
【题目描述】
在程序中定义一函数digit(n,k)，它能分离出整数n从右边数第k个数字。

【输入】
正整数n和k。

【输出】
一个数字。

【输入样例】
31859 3
【输出样例】
8
*/
#include <iostream>
using namespace std;

int digit(int n, int k)
{
	if (k - 1 == 0)
		return n % 10;
	return digit(n / 10, k - 1);
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		cout << digit(n, k) << endl;
	}
	return 0;
}
