/*
【题目描述】
求两个不超过200位的非负整数的积。

【输入】
有两行，每行是一个不超过200位的非负整数，没有多余的前导0。

【输出】
一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

【输入样例】
12345678900
98765432100
【输出样例】
1219326311126352690000
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char al[210], bl[210];
	while (cin >> al >> bl)
	{
		int a[210] = {0}, b[210] = {0}, c[40100] = {0};
		int la = strlen(al), lb = strlen(bl), lc = 0, x = 0;
		
		for (int i = 0; i < la; i++)
			a[la - i] = al[i] - 48;
			
		for (int i = 0; i < lb; i++)
			b[lb - i] = bl[i] - 48;
			
		for (int i = 1; i <= la; i++)
		{
			x = 0;
			for (int j = 1; j <= lb; j++)
			{
				c[i + j - 1] = a[i] * b[j] + x + c[i + j - 1];
				x = c[i + j - 1] / 10;
				c[i + j - 1] %= 10;
			}
			c[i + lb] = x;
		}
		
		lc = la + lb;
		
		while (c[lc] == 0 && lc > 1)
			lc--;
		
		for (int i = lc; i > 0; i--)
			cout << c[i];
		
	} 
	return 0;
}
