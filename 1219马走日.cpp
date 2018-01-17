/*
【题目描述】
马在中国象棋以日字形规则移动。

请编写一段程序，给定n×m大小的棋盘，以及马的初始位置(x，y)，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

【输入】
第一行为整数T(T < 10)，表示测试数据组数。

每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n,m,x,y。(0≤x≤n-1,0≤y≤m-1, m < 10, n < 10)。

【输出】
每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。

【输入样例】
1
5 4 0 0
【输出样例】
32
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20;
int t, n, m, sx, sy, b[N][N] = {0}, num = 0;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int dfs(int x, int y)
{
	int pn = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 0)
				break;
			pn++;
		}
	if (pn == n *m)
	{
		num++;
		return 0;
	}
	
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !b[nx][ny])
		{
			b[nx][ny] = 1;
			dfs(nx, ny);
			b[nx][ny] = 0;
		}
	}
		
	return 0;
}
int main()
{
	cin >> t;
	while (t)
	{
		cin >> n >> m >> sx >> sy;
		num = 0;
		memset(b, 0, sizeof(b));
		b[sx][sy] = 1;
		dfs(sx, sy);
		cout << num << endl;
		t--;
	}
	return 0;
}
