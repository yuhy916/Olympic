/*
【题目描述】
排列与组合是常用的数学方法，其中组合就是从n个元素中抽出r个元素(不分顺序且r≤n)，我们可以简单地将n个元素理解为自然数1，2，…，n，从中任取r个数。

现要求你用递归的方法输出所有组合。

例如n＝5，r＝3，所有组合为：

1 2 3   1 2 4   1 2 5   1 3 4   1 3 5   1 4 5   2 3 4   2 3 5   2 4 5   3 4 5

【输入】
一行两个自然数n、r(1<n<21，1≤r≤n)。

【输出】
所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。

【输入样例】
5 3
【输出样例】
  1  2  3
  1  2  4
  1  2  5
  1  3  4
  1  3  5
  1  4  5
  2  3  4
  2  3  5
  2  4  5
  3  4  5
*/
#include <iostream>
#include <iomanip>
using namespace std;

int n, r;
int a[21] = {0}, b[21] = {0};

int print()
{
	for (int i = 1; i <= r; i++)
		cout << setw(3) <<a[i];
	cout << endl;
	return 0;
}

int search(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (!b[i] && i > a[x-1])
		{
			b[i] = 1;
			a[x] = i;
			if (x == r)
				print();
			else
				search(x + 1);
			b[i] = 0;
		}
		
	}
	return 0;
}

int main()
{
	
	while (cin >> n >> r)
	{
		search(1);
	}
	return 0;
}
