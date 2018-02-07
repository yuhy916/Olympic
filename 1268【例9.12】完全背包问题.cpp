/*
【题目描述】
设有n种物品，每种物品有一个重量及一个价值。但每种物品的数量是无限的，同时有一个背包，最大载重量为M，今从n种物品中选取若干件(同一种物品可以多次选取)，使其重量的和小于等于M，而价值的和为最大。

【输入】
第一行：两个整数，M(背包容量，M≤200)和N(物品数量，N≤30)；

第2..N+1行：每行二个整数Wi,Ci，表示每个物品的重量和价值。

【输出】
仅一行，一个数，表示最大总价值。

【输入样例】
10 4
2 1
3 3
4 5
7 9
【输出样例】
max=12
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
		for (int j = w[i]; j <= m; j++)
			dp[j] = max(dp[j], dp[j-w[i]] + c[i]);	
	
	cout << "max=" << dp[m] << endl;
	return 0;
} 
