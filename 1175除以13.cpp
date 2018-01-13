/*
【题目描述】
输入一个大于0的大整数N，长度不超过100位，要求输出其除以13得到的商和余数。

【输入】
一个大于0的大整数，长度不超过100位。

【输出】
两行，分别为整数除法得到的商和余数。

【输入样例】
2132104848488485
【输出样例】
164008065268345
0
*/
#include <iostream>
using namespace std;

int init(int * a)
{
	string s;
	cin >> s;
	a[0] = s.length();
	for (int i = 1; i <= a[0]; i++)
		a[i] = s[i-1] - '0';
	return 0;
}

int main()
{
	int a[110] = {0}, c[110] = {0}, x = 0;
	init(a);
	for (int i = 1; i <= a[0]; i++)
	{
		c[i] = (10 * x + a[i]) / 13;
		x = (10 * x + a[i]) % 13;
	}
	c[0] = 1;
	while (c[c[0]] == 0 && c[0] < a[0])
		c[0]++;
	for (int i = c[0]; i <= a[0]; i++)
		cout << c[i];
	cout << endl << x << endl;
	return 0;
} 
