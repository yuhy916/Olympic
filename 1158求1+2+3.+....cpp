/*
【题目描述】
用递归的方法求1+2+3+……+N的值。

【输入】
输入n。

【输出】
输出和。

【输入样例】
5
【输出样例】
15
*/
#include <iostream>
using namespace std;

int sum(int n)
{
	if (n == 1)
		return 1;
	return sum(n-1) + n;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int s = sum(n);
		cout << s << endl;
	}
	return 0;
}
