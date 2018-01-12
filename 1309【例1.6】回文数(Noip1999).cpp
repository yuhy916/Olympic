/*
【题目描述】
若一个数（首位不为零）从左向右读与从右向左读都是一样，我们就将其称之为回文数。例如：给定一个 10进制数 56，将 56加 65（即把56从右向左读），得到 121是一个回文数。又如，对于10进制数87，

STEP1： 87＋78= 165 STEP2： 165＋561= 726

STEP3： 726＋627＝1353 STEP4：1353+3531=4884

在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

写一个程序，给定一个N（2＜N＜＝10或N=16）进制数 M．求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible” 。

【输入】
给定一个N（2＜N＜＝10或N=16）进制数M。

【输出】
最少几步。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible”。

【输入样例】
9 87
【输出样例】
6
*/
#include <iostream>
#include <cstring>
using namespace std;

int init(int * a)
{
	string s;
	cin >> s;
	a[0] = s.length();
	for (int i = 1; i <= a[0]; i++)
	{
		if (s[a[0] - i] >= '0' && s[a[0] - i] <= '9')
			a[i] = s[a[0] - i] - '0';
		else
			a[i] = s[a[0] - i] - 'A' + 10;
	}
	return 0;
}

int isHW(int * a)
{
	for (int i = 1; i <= a[0]; i++)
		if (a[i] != a[a[0] - i + 1])
			return 0;
	return 1;
}

int rev(int *a, int *b)
{
	memset(b, 0, sizeof(b));
	b[0] = a[0];
	for (int i = 1; i <= a[0]; i++)
		b[i] = a[a[0] - i + 1];
	return 0;
}

int add(int *a, int *b, int n)
{
	int l = a[0] > b[0] ? a[0] : b[0];
	for (int i = 1; i <= l; i++)
	{
		a[i] += b[i];
		
		a[i+1] += a[i] / n;
		a[i] %= n; 
	}
	
	a[0] = a[l+1] > 0 ? l + 1 : l;
	return 0;
}

int main()
{
	int m[1000] = {0}, t[1000] = {0}, n, step = 0;
	cin >> n;
	init(m);
	
	while (step <= 30)
	{	
		if (isHW(m))
			break;
		rev(m, t);
		add(m, t, n);
		step++;
	}
	if (step > 30)
		cout << "Impossible" << endl;
	else
		cout << step << endl;
	
	return 0;
}
