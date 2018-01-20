/*
【题目描述】
有n个人在一个水龙头前排队接水，假如每个人接水的时间为Ti，请编程找出这n个人排队的一种顺序，使得n个人的平均等待时间最小。

【输入】
共两行，第一行为n(1≤n≤1000)；第二行分别表示第1个人到第n个人每人的接水时间T1，T2，…，Tn，每个数据之间有1个空格。

【输出】
有两行，第一行为一种排队顺序，即1到n的一种排列；第二行为这种排列方案下的平均等待时间(输出结果精确到小数点后两位)。

【输入样例】
10							
56 12 1 99 1000 234 33 55 99 812
【输出样例】
3 2 7 8 1 4 9 6 10 5
291.90
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1100;
int n, t[N], b[N] = {0}, tmp = 0, flag = 1;
float ave = 0.0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		b[i] = i + 1;
	}
	for (int i = 0; i < n && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (t[j] <= t[j+1])
			{
				tmp = t[j];
				t[j] = t[j+1];
				t[j+1] = tmp;
				tmp = b[j];
				b[j] = b[j+1];
				b[j+1] = tmp;
				flag = 1;
			}
		}			
	}
	
	for (int i = 0; i < n; i++)
		ave += (n - i - 1) * t[n-i-1];
		
	for (int i = n - 1; i >= 0; i--)
	{
		cout << b[i];
		if (i > 0)
			cout << " ";
	}
	printf("\n%.2f\n", ave / n);
	
	return 0;
}
