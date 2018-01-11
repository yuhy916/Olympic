/*
【题目描述】
输入一个非负整数，输出这个数的倒序数。例如输入123，输出321。

【输入】
输入一个非负整数(保证个位不为零）。

【输出】
输出倒序的数。

【输入样例】
123
【输出样例】
321
*/
#include <iostream>
using namespace std;

int rev(int n)
{
	if (n == 0)
		return 0;
	cout << n % 10;
	rev(n / 10);
	return 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		rev(n);
		cout << endl; 
	}
	return 0;
}
