/*
【题目描述】
已知:

m=max(a,b,c)/(max(a+b,b,c)×max(a,b,b+c))
输入a,b,c，求m。把求三个数的最大数max(x,y,z)分别定义成函数和过程来做。

【输入】
输入a,b,c。

【输出】
求m，保留到小数点后三位。

【输入样例】
1 2 3
【输出样例】
 0.200
*/
#include <iostream>
#include <cstdio>
using namespace std;

float max(int x, int y, int z)
{
	int max = 0;
	max = x > y ? x : y;
	max = max > z ? max : z;
	return max;
}

int main()
{
	int a, b, c;
	float m;
	cin >> a >> b >> c;
	m = max(a, b, c) / (max(a+b, b, c) * max(a, b, b+c));
	printf("%.3f\n", m);
	return 0;
}
