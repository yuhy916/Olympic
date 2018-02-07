/*
【题目描述】
设有由n(1≤n≤200)个不相同的整数组成的数列，记为:b(1)、b(2)、……、b(n)且b(i)≠b(j)(i≠j)，若存在i1<i2<i3<…<ie 且有b(i1)<b(i2)<…<b(ie)则称为长度为e的不下降序列。程序要求，当原数列出之后，求出最长的不下降序列。

例如13，7，9，16，38，24，37，18，44，19，21，22，63，15。例中13，16，18，19，21，22，63就是一个长度为7的不下降序列，同时也有7 ，9，16，18，19，21，22，63组成的长度为8的不下降序列。

【输入】
第一行为n,第二行为用空格隔开的n个整数。

【输出】
第一行为输出最大个数max(形式见样例)；

第二行为max个整数形成的不下降序列,答案可能不唯一，输出一种就可以了，本题进行特殊评测。

【输入样例】
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15
【输出样例】
max=8
7 9 16 18 19 21 22 63
*/
#include <iostream>
using namespace std;

const int N = 210, INF = 9999999;
int maxn, ri;
int a[N], r[N], dp[N]; // dp[i]:=以a[i]为结尾的最长不下降序列数

int solve()
{
	int res = 0;
	for (int i = 0; i < maxn; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i])
				dp[i] = max(dp[i], dp[j] + 1);
//		res = max(res, dp[i]);
		if (dp[i] > res)
			res = dp[i], ri = i;
	}
	return res;
}

int main()
{
	cin >> maxn;
	for (int i = 0; i < maxn; i++)
		cin >> a[i];
	int res = solve();
	cout << "max=" << res << endl;

	fill(r, r+res+1, INF);
	
	int num = res;
	while (num)
	{
		for (int i = ri; i >= 0; i--)
			if (dp[i] == num && a[i] <= r[num])
			{
				r[num-1] = a[i];
				ri = i-1;
				break;
			}
		num--;
	}

	for (int i = 0; i < res; i++)
	{
		cout << r[i];
		if (i < res - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}
