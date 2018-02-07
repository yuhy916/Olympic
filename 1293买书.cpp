/*
【题目描述】
小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。

问小明有多少种买书方案？（每种书可购买多本）

【输入】
一个整数 n，代表总共钱数。（0 ≤ n ≤ 1000）

【输出】
一个整数，代表选择方案种数。

【输入样例】
20
【输出样例】
2
【提示】
样例输入

样例输入2：

15

样例输入3：

0

样例输出

样例输出2：

0

样例输出3：

0
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, b[5] = {0, 10, 20, 50, 100}, dp[N];

int main()
{
	cin >> n;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	dp[0] = 1;
	for (int i = 1; i <= 4; i++)
		for (int j = b[i]; j <= n; j=j+10)
			dp[j] += dp[j-b[i]];
			
	cout << dp[n] << endl;
	
	return 0;
}
