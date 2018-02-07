/*
【题目描述】
下图表示城市之间的交通路网，线段上的数字表示费用，单向通行由A->E。试用动态规划的最优化原理求出A->E的最省费用。



如图：求v1到v10的最短路径长度及最短路径。

【输入】
第一行为城市的数量N;

后面是N*N的表示两个城市间费用组成的矩阵。

【输出】
A->E的最省费用。

【输入样例】
10
0  2  5  1  0  0  0  0  0  0
0  0  0  0 12 14  0  0  0  0
0  0  0  0  6 10  4  0  0  0
0  0  0  0 13 12 11  0  0  0
0  0  0  0  0  0  0  3  9  0
0  0  0  0  0  0  0  6  5  0
0  0  0  0  0  0  0  0 10  0
0  0  0  0  0  0  0  0  0  5
0  0  0  0  0  0  0  0  0  2
0  0  0  0  0  0  0  0  0  0
【输出样例】
minlong=19
1 3 5 8 10
*/
#include <iostream>
using namespace std;

const int N = 10000, INF = 99999;
int n, a[N][N], dp[N], b[N], x = 0; // dp[i]:=i到n的最短路径长度

int solve()
{
	dp[n] = 0;
	for (int i = n-1; i > 0; i--)
		for (int j = i+1; j <= n; j++)
			if (a[i][j] != 0 && dp[j] != INF)
				if (dp[i] > dp[j] + a[i][j])
				{
					dp[i] = dp[j] + a[i][j];
					b[i] = j;
//					cout << "b[" << i << "]=" << j <<  endl;
				}
} 

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		dp[i] = INF;
	solve();
	cout << "minlong=" << dp[1] << endl;
	x = 1;
	while (x)
	{
		cout << x << " ";
		x = b[x]; 
	}
	cout << endl;
	return 0;
}
