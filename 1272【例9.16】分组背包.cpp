/*
【题目描述】
一个旅行者有一个最多能装V公斤的背包，现在有n件物品，它们的重量分别是W1，W2，...,Wn，它们的价值分别为C1,C2,...,Cn。这些物品被划分为若干组，每组中的物品互相冲突，最多选一件。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

【输入】
第一行：三个整数，V(背包容量，V≤200)，N(物品数量，N≤30)和T(最大组号，T≤10)；

第2..N+1行：每行三个整数Wi,Ci,P，表示每个物品的重量，价值，所属组号。

【输出】
仅一行，一个数，表示最大总价值。

【输入样例】
10 6 3
2 1 1
3 3 1
4 8 2
6 9 2
2 8 3
3 9 3
【输出样例】
20
*/
#include <iostream>
using namespace std;

const int V = 210, N = 35, T = 15;

int v, n, t;
int w[N], c[N], p[N], dp[V];

int main()
{
	cin >> v >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> c[i] >> p[i];
	
	for (int k = 1; k <= t; k++)
		for (int j = v; j >= 0; j--)
			for (int i = 1; i <= n; i++)
				if (k == p[i] && j >= w[i])
					dp[j] = max(dp[j], dp[j-w[i]] + c[i]);
		
	cout << dp[v] << endl;
	return 0;
}
