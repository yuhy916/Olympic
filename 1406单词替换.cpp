/*
【题目描述】
输入一个字符串，以回车结束（字符串长度≤200）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。

【输入】
第1行是包含多个单词的字符串 s；

第2行是待替换的单词a(长度 ≤ 100)；

第3行是a将被替换的单词b(长度 ≤ 100)。

s,a,b最前面和最后面都没有空格。

【输出】
输出只有 1 行，将s中所有单词a替换成b之后的字符串。

【输入样例】
You want someone to help you
You
I
【输出样例】
I want someone to help you
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[220], a[110], b[110];
	char t[110] = {0};
	int p[220] = {0};
	int ls, la, lb, n = 0;
	
	gets(s);
	gets(a);
	gets(b);
	
	ls = strlen(s);
	la = strlen(a);
	lb = strlen(b);
	
	for (int i = 0; i < ls + 1; i++)
	{
		if (s[i] != ' ' && s[i] != '\0')
		{
			t[n++] = s[i]; // 处理忽略空格
		}
		else
		{
			if (strcmp(t, a) == 0)
			{
				p[i - la] = 1;
			}
			memset(t, 0, sizeof(t));
			n = 0;
		}
	}
	
	for (int i = 0; i < ls  + 1; i++)
	{
		if (p[i])
		{
			for (int j = 0; j < lb; j++)
			{
				t[n+j] = b[j];
			}
			n += lb;
			i += la;
		}
		t[n++] = s[i];			
	}
	
	cout << t << endl;
	
	return 0;
}
