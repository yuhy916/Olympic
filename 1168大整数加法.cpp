/*
【题目描述】
求两个不超过200位的非负整数的和。

【输入】
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。

【输出】
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

【输入样例】
22222222222222222222
33333333333333333333
【输出样例】
55555555555555555555
*/
#include <iostream>
#include <cstring>
using namespace std;

int init(int * a)
{
	string s;
	cin >> s;
	memset(a, 0, sizeof(a));
	a[0] = s.length();
	for (int i = 1; i <= a[0]; i++)
		a[i] = s[a[0] - i] - '0';
	return 0;
}

int add(int * a, int * b)
{
	int l = a[0] > b[0] ? a[0] : b[0];
	for (int i = 1; i <= l; i++)
	{
		a[i] += b[i];
		a[i+1] += a[i] / 10;
		a[i] %= 10;
	}
	
	a[0] = a[l+1] > 0 ? l + 1 : l;
	
	for (int i = a[0]; i > 0 && a[0] > 1; i--)
	{
		if (a[i] != 0)
			break;
		a[0]--;
	}
	return 0;
}

int main()
{
	int a[210] = {0}, b[210] = {0};
	init(a);
	init(b);
	add(a, b);
	
	for (int i = a[0]; i > 0; i--)
		cout << a[i];
	cout << endl;	
	
	return 0;
}
