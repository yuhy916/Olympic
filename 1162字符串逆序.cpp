/*
【题目描述】
输入一串以‘！’结束的字符，按逆序输出。

【输入】
如题述。

【输出】
如题述。

【输入样例】
abc!
【输出样例】
cba
*/
#include <iostream>
#include <cstring>
using namespace std;

int rev(char * c)
{
	int l = strlen(c);
	if (*c == '!')
		return 0;
	rev(c+1);
	cout << *c;
	return 0;
}
int main()
{
	char c[1000000];
	while (cin >> c)
	{
		rev(c);	
		cout << endl;	
	}
	return 0;	
}
