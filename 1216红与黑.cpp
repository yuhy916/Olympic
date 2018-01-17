/*
【题目描述】
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

【输入】
包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下:

1）‘.’：黑色的瓷砖；

2）‘#’：白色的瓷砖；

3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。

当在一行中读入的是两个零时，表示输入结束。

【输出】
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

【输入样例】
6 9 
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
0 0
【输出样例】
45
*/
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int N = 30, INF = 1000000;

int w, h, sx, sy, num = 0;
int d[N][N] = {0}, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char a[N][N];

int bfs()
{
	queue<P> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			d[i][j] = INF;
	d[sx][sy] = 0;
	q.push(P(sx, sy));
	num++;
	while (q.size())
	{
		P p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx >= 0 && nx < h && ny >=0 && ny < w && d[nx][ny] == INF && a[nx][ny] != '#')
			{
				q.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
				num++;
			}
		}
	}
	return 0;
}

int main()
{
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break; 
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		num = 0;
		bfs();
		cout << num << endl;
	}
	
	return 0;
}
