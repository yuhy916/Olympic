/*
【题目描述】
找出正整数M和N之间（N不小于M）的所有真素数。

真素数的定义：如果一个正整数P为素数，且其反序也为素数，那么P就为真素数。

例如，11，13均为真素数，因为11的反序还是为11，13的反序为31也为素数。

【输入】
输入两个数M和N，空格间隔，1≤M≤N≤100000。

【输出】
按从小到大输出M和N之间（包括M和N）的真素数，逗号间隔。如果之间没有真素数，则输出No。

【输入样例】
10 35
【输出样例】
11,13,17,31

*/
#include <iostream>
#include <cmath>
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

int rev(int n)
{
	int a[10] = {0};
	int num = 0;
	int m = 0;
	
	while (n != 0)
	{
		a[num] = n % 10;
		n /= 10;
		num++;
	}
	
	for (int i = 0; i < num; i++)
	{
		m *= 10;
		m += a[i];
	}
	return m;
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int num = 0, a[100010] = {0};
		for (int i = m; i <= n; i++)
		{
			if (isP(i) && isP(rev(i)))
			{
				a[num++] = i;
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << a[i];
			if(i != num - 1)
				cout << ",";
		}
		if (num == 0)
		{
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}

