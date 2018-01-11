/*
【题目描述】
阿克曼(Ackmann)函数A(m，n)中，m，n定义域是非负整数(m≤3,n≤10)，函数值定义为：

akm(m,n) = n+1;         (m=0时)

akm(m,n) = akm(m-1,1);  (m>0,n=0时)

akm(m,n) = akm(m-1,akm(m, n-1)); （m,n>0时)

【输入】
输入m和n。

【输出】
函数值。

【输入样例】
2 3
【输出样例】
9
*/
#include <iostream>
using namespace std;

int akm(int m, int n)
{
	if (m == 0)
		return n+1;
	if (n == 0 && m > 0)
		return akm(m-1, 1);
	if (m > 0 && n > 0)
		return akm(m -1, akm(m, n-1));
	return 0;
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << akm(m, n) << endl;
	}
	return 0;
}
