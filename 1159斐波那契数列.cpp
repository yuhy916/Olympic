/*
【题目描述】
用递归函数输出斐波那契数列第n项。0,1，1，2，3，5，8，13……

【输入】
一个正整数n,表示第n项。

【输出】
第n项是多少。

【输入样例】
3
【输出样例】
1
*/
#include <iostream>
using namespace std;

int f(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return f(n-1) + f(n-2);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << f(n) << endl;
	}
	return 0;
}
