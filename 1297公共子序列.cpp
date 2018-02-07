/*
【题目描述】
我们称序列Z=<z1,z2,...,zk>是序列X=<x1,x2,...,xm>的子序列当且仅当存在严格上升的序列<i1,i2,...,ik>，使得对j=1,2,...,k,有xij=zj。比如Z=<a,b,f,c> 是X=<a,b,c,f,b,c>的子序列。

现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。

【输入】
输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。

【输出】
对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。

【输入样例】
abcfbc abfcab
programming contest 
abcd mnp
【输出样例】
4
2
0
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 210;
int m = 0, n = 0, dp[N][N]; 
// dp[i][j]:=长度为i的a序列与长度为j的b序列的最大公共子序列的长度 
char a[N], b[N];

int solve()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i] == b[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);	
	return 0;
} 

int main()
{
	while(cin >> a >> b)
	{
		memset(dp, 0, sizeof(dp));
		m = strlen(a), n = strlen(b);
		solve();
		cout << dp[m][n] << endl;
	}
	
	return 0;
}
