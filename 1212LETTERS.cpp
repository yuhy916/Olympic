/*
【题目描述】
给出一个roe*col的大写字母矩阵，一开始的位置为左上角，你可以向上下左右四个方向移动，并且不能移向曾经经过的字母。问最多可以经过几个字母。

【输入】
第一行，输入字母矩阵行数R和列数S，1≤ R,S≤20。

接着输出R行S列字母矩阵。

【输出】
最多能走过的不同字母的个数。

【输入样例】
3 6
HFDFFB
AJHGDH
DGAGEH
【输出样例】
6
*/
#include <iostream>
#include <cstring>
using namespace std;

int r, s, b[26] = {0};
char a[21][21];
int maxn = 0;

int search(int x, int y, int num)
{
	b[a[x][y]-'A'] = 1;
	num++;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = x + dx, ny = y + dy; 
			if (nx >= 0 && nx < r && ny >= 0 && ny < s && (dx + dy == 1 || dx + dy == -1) && !b[a[nx][ny]-'A'])
				search (nx, ny, num);
		} 
	b[a[x][y]-'A'] = 0;
	maxn = maxn > num ? maxn : num;
	return 0;
}

int main()
{
	while (cin >> r >> s) 
	{
		for (int i = 0; i < r; i++)
			for (int j = 0; j < s; j++)
				cin >> a[i][j];
		maxn = 0;
		memset(b, 0, sizeof(b));
		search(0, 0, 0);
		cout << maxn << endl;		
	}
	return 0;
}
