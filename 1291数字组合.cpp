/*
【题目描述】
有n个正整数，找出其中和为t(t也是正整数)的可能的组合方式。如：

n=5,5个数分别为1,2,3,4,5，t=5；

那么可能的组合有5=1+4和5=2+3和5=5三种组合方式。

【输入】
输入的第一行是两个正整数n和t，用空格隔开，其中1≤n≤20,表示正整数的个数，t为要求的和(1≤t≤1000);

接下来的一行是n个正整数，用空格隔开。

【输出】
和为t的不同的组合方式的数目。

【输入样例】
5 5
1 2 3 4 5
【输出样例】
3
*/
#include <iostream>
using namespace std;

const int N = 25, T = 1010;
int n, t;
int a[N], dp[T];

int solve()
{
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = t; j >= a[i]; j--)
				dp[j] += dp[j-a[i]]; 
}

int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	solve();
	cout << dp[t] << endl;
	return 0;
}
