/*
【题目描述】
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。

现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2）。

【输入】
第 1 行为一个字符串，其中只含字母，表示给定单词；

第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

【输出】
只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从0开始）；如果单词在文章中没有出现，则直接输出一个整数-1。

【输入样例】
To
to be or not to be is a question
【输出样例】
2 0
【提示】
样例输入:

样例 #2：

to

Did the Ottoman Empire lose its power at that time

样例输出:

样例 #2：

-1

数据范围
1≤ 单词长度≤10。 
1≤ 文章长度≤1,000,000。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 注意：strlwr()和strupr()不是标准库函数，只能在windows下（VC、MinGW等）使用，Linux GCC中需要自己定义。
char *strupr(char *str)
{
	char *orign = str;
	for (; *str != '\0'; str++)
	*str = tolower(*str);
	return orign;
}
	
int main()
{
	const int N = 1000000 + 10;
	char w[20], t[N];
	char b[20] = {0};
	int n = 0;
	int p = 0, num = 0, flag = 0;
	int lw = 0, lt = 0;

	cin >> w;
	getchar();
	gets(t);

	// 将w,t同时转成大写	
	strupr(w); 
	strupr(t); 
	
	lw = strlen(w);
	lt = strlen(t);
	
//	for (int i = 0; i < lw; i++)
//        if(isalpha(w[i]) && w[i] >= 'A' && w[i] <= 'Z')
//            w[i] = 'a' + w[i] - 'A';
//    for (int i = 0; i < lt; i++)
//        if(isalpha(t[i]) && t[i] >= 'A' && t[i] <= 'Z')
//            t[i] = 'a' + t[i] - 'A';


//	方法一 
	for (int i = 0; i < lt + 1; i++)
	{
		if (t[i] != ' ' && t[i] != '\0')
		{
			b[n++] = t[i]; // 处理忽略空格
		}
		else
		{
			if (strcmp(b, w) == 0)
			{
				if (num == 0)
				{
					p = i - lw;
				}
				num++;
			}
			memset(b, 0, sizeof(b));
			n = 0;
		}
	}

// 方法二 
//	for (int i = 0; i < lt; i++)
//	{
//		int j;
//		for (j = 0; j < lw; j++)
//		{
//			flag = 1;
//			if (t[i+j] != w[j])
//			{
//				flag = 0;
//				break;
//			}
//			
//		}
//		
//		if (flag)
//		{
//			// 开头
//			if (i == 0 && t[i+j] == ' ')
//			{
//				num++;
//			} 
//			// 结尾 
//			else if (i + j == lt && t[i-1] == ' ')
//			{
//				num++;
//			}
//			// 中间 
//			else if (t[i-1] == ' ' && t[i+j] == ' ')
//			{
//				num++;
//			}
//			else
//			{
//				continue;
//			}
//			if (num == 1)
//			{
//				p = i;
//			}
//		}
//	}

	if (num)
	{
		cout << num << " " << p << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	return 0;
}

