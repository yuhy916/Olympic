/*
【题目描述】
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。

给出一个正整数a，要求菲波那契数列中第a个数对1000取模的结果是多少。

【输入】
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 ≤ a ≤ 1000000)。

【输出】
n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数对1000取模得到的结果。

【输入样例】
4
5
2
19
1
【输出样例】
5
1
181
1
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long a;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			long long f0 = 1;
			long long f1 = 1;
			long long f2;
			for (int j = 3; j <= a; j++)
			{
				f2 = (f0 + f1) % 1000;
				f1 = f0;
				f0 = f2;
			}
			cout << f0 << endl;
		}
	}
	return 0;	
} 
