/*
【题目描述】
为了庆贺班级在校运动会上取得全校第一名成绩，班主任决定开一场庆功会，为此拨款购买奖品犒劳运动员。期望拨款金额能购买最大价值的奖品，可以补充他们的精力和体力。

【输入】
第一行二个数n(n≤500)，m(m≤6000)，其中n代表希望购买的奖品的种数，m表示拨款金额。

接下来n行，每行3个数，v、w、s，分别表示第I种奖品的价格、价值（价格与价值是不同的概念）和能购买的最大数量（买0件到s件均可），其中v≤100，w≤1000，s≤10。

【输出】
一行：一个数，表示此次购买能获得的最大的价值（注意！不是价格）。

【输入样例】
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
【输出样例】
1040
*/
#include <iostream>
using namespace std;

const int N = 510, M = 6010, S = 11;
int n, m;
int v[N], w[N], s[N], v1[N*S], w1[N*S], dp[M];

int main()
{
	cin >> n >> m;
	
	int num = 0;
	for (int i = 1; i <= n; i++)
	{ 
		cin >> v[i] >> w[i] >> s[i];
		// 转换成01背包问题 
		for (int j = 0; j < s[i]; j++)
		{
			num++;
			v1[num] = v[i];
			w1[num] = w[i];
		}
	} 
	
	for (int i = 1; i <= num; i++)
		for (int j = m; j >= v1[i]; j--)
			dp[j] = max(dp[j], dp[j-v1[i]] + w1[i]);
	
	cout << dp[m] << endl;
	
	return 0;
} 
