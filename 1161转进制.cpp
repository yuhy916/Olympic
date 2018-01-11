/*
【题目描述】
用递归算法将一个十进制数X转换成任意进制数M（M≤16）。

【输入】
一行两个数，第一个十进制数X，第二个为进制M。

【输出】
输出结果。

【输入样例】
31 16 ｛将十进制31转化为十六进制数｝
【输出样例】
1F
*/
#include <iostream>
using namespace std;

int toM(int n, int m)
{
	char t;
	if (n == 0)
		return 0;
	
	toM(n / m, m);
	
	if (n % m >= 10)
	{
		t = n % m - 10 + 'A';
		cout << t;
		return 0;
	}
	cout << n % m;
	return 0;
}

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		toM(n, m);
		cout << endl;
	}
	return 0;
}
