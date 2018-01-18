/*
【题目描述】
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

【输入】
第一行是测试数据的数目t（0 ≤ t ≤ 20）。以下每行均包含二个整数M和N，以空格分开。1≤M，N≤10。

【输出】
对输入的每组数据M和N，用一行输出相应的K。

【输入样例】
1
7 3
【输出样例】
8
*/
#include <iostream>
#include <cstring>
using namespace std;

int t, m, n, num = 0, a[20] = {0};

int solve(int x, int s)
{
	if (s == m && x <= n + 1)
	{
		num++;
		return 0;
	}
	else if (s > m || x > n + 1)
		return 0;
	
	for (int i = 1; i <= m; i++)
	{
		if (a[x-1] > i)
			continue;
		a[x] = i;
		solve(x + 1, s + a[x]);
	}
	return 0;
}

int main()
{
	cin >> t;
	while (t)
	{
		cin >> m >> n;
		num = 0; 
		memset(a, 0, sizeof(20));
		solve(1, 0);
		cout << num << endl;
		t--;
	}
	return 0;
}
