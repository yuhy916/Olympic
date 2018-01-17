/*
【题目描述】
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

【输入】
输入含有多组测试数据。

每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n ≤ 8 , k ≤ n

当为-1 -1时表示输入结束。

随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。

【输出】
对于每一组数据，给出一行输出，输出摆放的方案数目C（数据保证C<2^31）。

【输入样例】
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1

【输出样例】
2
1
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n, k, col[N] = {0}, row[N] = {0}, num = 0;
char a[N][N];

int dfs(int x)
{
	if (x > k)
	{
		num++;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (row[x-1] < i)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!col[j] && a[i][j] == '#')
				{
					row[x] = i;
					col[j] = 1;
					dfs(x+1);
					col[j] = 0;
				}
			}
		}
	}
		
	return 0;
}

int main()
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		num = 0;
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		
		dfs(1);
		cout << num << endl;
	}
	return 0;
} 
