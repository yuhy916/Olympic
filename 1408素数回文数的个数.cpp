/*
【题目描述】
求11到n之间（包括n），既是素数又是回文数的整数有多少个。

【输入】
一个大于11小于1000的整数n。

【输出】
11到n之间的素数回文数个数。

【输入样例】
23
【输出样例】
1
【提示】
提示:

回文数指左右对称的数，如：292，333。
*/
#include <iostream>
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

int isHW(int n)
{
	if (n < 100)
	{
		// 两位数
		return n / 10 == n % 10 ? 1 : 0;
	}
	// 三位数 
	return n / 100 == n % 10 ? 1 : 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int num = 0;
		for (int i = 11; i <= n; i++)
			if (isP(i) && isHW(i))
				num++;
		cout << num << endl;
	}
	return 0;
}
