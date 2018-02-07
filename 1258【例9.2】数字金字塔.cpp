/*
【题目描述】
观察下面的数字金字塔。写一个程序查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以从当前点走到左下方的点也可以到达右下方的点。



在上面的样例中,从13到8到26到15到24的路径产生了最大的和86。

【输入】
第一个行包含R(1≤ R≤1000)，表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

所有的被供应的整数是非负的且不大于100。

【输出】
单独的一行，包含那个可能得到的最大的和。

【输入样例】
5
13
11 8
12 7  26
6  14 15 8
12 7  13 24 11
【输出样例】
86
*/
#include <iostream>
using namespace std;
const int N = 1100;
int r;
int a[N][N];
int dp[N][N];

int solve()
{
	dp[1][1] = a[1][1];
	int t = 0;
	for (int i = 2; i <= r; i++)
		for (int j = 1; j <= i; j++)
		{
			t = max(dp[i-1][j-1], dp[i-1][j]);
			if (i < r)
				dp[i][j] = t + a[i][j];
			else
				dp[i][j] = max(dp[i][j-1], t + a[i][j]);
		}
	return dp[r][r];
}

int main()
{
	cin >> r;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	cout << solve() << endl;
	return 0;
}
