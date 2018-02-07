/*
【题目描述】
一个旅行者有一个最多能装M公斤的背包，现在有n件物品，它们的重量分别是W1，W2，...,Wn,它们的价值分别为C1,C2,...,Cn，求旅行者能获得最大总价值。

【输入】
第一行：两个整数，M(背包容量，M≤200)和N(物品数量，N≤30)；

第2..N+1行：每行二个整数Wi，Ci，表示每个物品的重量和价值。

【输出】
仅一行，一个数，表示最大总价值。

【输入样例】
10 4
2 1
3 3
4 5
7 9
【输出样例】
12
*/
#include <iostream>
using namespace std;

const int M = 210, N = 35;
int m, n;
int w[N], c[N], dp[M];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> c[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]] + c[i]);
	
	cout << dp[m] << endl;
	return 0;
}
