/*
【题目描述】
给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。

【输入】
第一行为n和m。

【输出】
一行，方案数。

【输入样例】
3 10        //3种面值组成面值为10的方案
1           //面值1
2           //面值2
5           //面值5
【输出样例】
10          //有10种方案
*/
#include <iostream>
using namespace std;

const long long N = 1000000;
long long n, m;
long long a[N], dp[N];

int main()
{
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	
	dp[0] = 1;
	for (long long i = 1; i <= n; i++)
		for (long long j= a[i]; j <= m; j++)
			dp[j] += dp[j-a[i]];
	
	cout << dp[m] << endl;
	return 0;
}
