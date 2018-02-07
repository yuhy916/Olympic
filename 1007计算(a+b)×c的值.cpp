/*
【题目描述】
给定3个整数a、b、c，计算表达式(a+b)*c的值。

【输入】
输入仅一行，包括三个整数a、b、c, 数与数之间以一个空格分开。

(－10,000<a,b,c<10,000)

【输出】
输出一行，即表达式的值。

【输入样例】
2 3 5
【输出样例】
25
*/
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a+b)*c << endl;; 
	return 0;
}
