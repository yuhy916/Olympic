/*
【题目描述】
6*9=42对于十进制来说是错误的，但是对于13进制来说是正确的。即, 6(13)* 9(13)= 42(13)， 而 42(13)=4*131+2*130=54(10)。

你的任务是写一段程序，读入三个整数p、q和 r，然后确定一个进制 B(2≤B≤40) 使得 p * q = r。 如果 B 有很多选择, 输出最小的一个。

例如：p=11, q=11, r=121.则有11(3)* 11(3)= 121(3)因为 11(3)= 1 * 31+ 1 * 30= 4(10)和121(3)=1*32+2*31+1*30=16(10)。对于进制 10，同样有11(10)* 11(10)= 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

【输入】
一行，包含三个整数p、q、r。 p、q、r的所有位都是数字，并且1 ≤ p、q、r ≤ 1,000,000。

【输出】
一个整数：即使得p*q=r成立的最小的B。如果没有合适的B，则输出0。

【输入样例】
6 9 42
【输出样例】
13
*/
#include <iostream>
using namespace std;

int toB(int n, int b)
{
	int num = 0;
	int a[10] = {0};
	int m = 0;
	
	while (n != 0)
	{
		a[num] = n % 10;
		n /= 10;
		num++;
	}
	
	while (num > 0)
	{
		m *= b;
		m += a[num - 1];
		num--;
	}
	
	return m;
}

int isB(int p, int q, int r, int b)
{
	p = toB(p, b);
	q = toB(q, b);
	r = toB(r, b);
	
	if (p * q == r)
		return 1;
		
	return 0;
}

int main()
{
	int p, q, r;
	while (cin >> p >> q >> r)
	{
		int i;
		for (i = 2; i <= 40; i++)
		{
			if (isB(p, q, r, i))
				break;
		}
		if (i > 40)
			cout << 0 << endl;
		else
			cout << i << endl; 
	}
	return 0;
}
