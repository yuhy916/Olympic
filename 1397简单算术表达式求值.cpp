/*
【题目描述】
两位正整数的简单算术运算（只考虑整数运算），算术运算为：

+，加法运算；

-，减法运算；

*，乘法运算；

/，整除运算；

%，取余运算。

算术表达式的格式为（运算符前后可能有空格）：

运算数 运算符 运算数

请输出相应的结果。

【输入】
一行算术表达式。

【输出】
整型算数运算的结果（结果值不一定为2位数，可能多于2位或少于2位）。

【输入样例】
32+64
【输出样例】
96
*/
#include <iostream>
using namespace std;

int main()
{
	int a, b, result;
	char c;
	cin >> a >> c >> b;
	
	switch(c)
	{
		case '+':
			result = a + b;
			break;
		case'-':
			result = a - b;
			break;
		case'*':
			result = a * b;
			break;
		case'/':
			result = a / b;
			break;
		case'%':
			result = a % b;
			break;
		default:
			break;
	}
	
	cout << result << endl;
	return 0;
}
