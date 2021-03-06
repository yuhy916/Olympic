/*
【题目描述】
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

【输入】
输入导弹依次飞来的高度。

【输出】
第一行：最多能拦截的导弹数；

第二行：要拦截所有导弹最少要配备的系统数。

【输入样例】
389 207 155 300 299 170 158 65
【输出样例】
6
2
*/
#include <iostream>
#include <cstdio> 

using namespace std;

const int N = 1010, INF = 30010;
int a[N], b[N], i = 0, res = 0, minn = 0, dp[N]; // dp[i]:=以a[i]为结尾的最长下降序列数

int main()
{
	while (cin >> a[i])
	{
		// 最长下降序列数
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] >= a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
		
		// 系统套数
		int x = 0, k = 0;
		for (k = 1; k <= minn; k++)             	// 计算由哪一套系统拦截导弹
       		if (b[k] >= a[i]) 
        		if (x == 0)
					x = k;
         		else if (b[k] < b[x]) 
					x = k;          				// 如果有多套系统可拦截，则选择上一次拦截高度最低的

		if (x == 0)									// 新增一套导弹拦截系统
		{
			minn++;
			x = minn;
		}
		b[x] = a[i];
		
		i++;
		
		if (getchar() == '\n')
			break;
	}
	cout << res << endl << minn << endl;
	
	return 0;
}
