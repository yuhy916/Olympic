/*
【题目描述】
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

【输入】
只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。

【输出】
共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；

第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

【输入样例】
error
【输出样例】
Lucky Word
2
【提示】
样例输入:

样例 #2：

olympic

样例输出:

样例 #2：

No Answer

0
*/
#include <iostream>
#include <cstring>
using namespace std;

int isP(int n)
{
	if (n <= 1)
		return 0;
	
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return 0;
	
	return 1;
}

int main()
{
	char c[110];
	
	while (cin >> c)
	{
		int a[26] = {0};
		int max = 0, min = 110, l;
		
		l = strlen(c);
		for (int i = 0; i < l; i++)
			a[c[i] - 'a']++;
			
		for (int i = 0; i < 26; i++)
		{
			if (a[i] == 0)
				continue;
			
			max = max >= a[i] ? max : a[i];
			min = min <= a[i] ? min : a[i];
			
		}
		if (isP(max - min))
		{
			cout << "Lucky Word" << endl;
			cout << max - min << endl;
		}
		else
		{
			cout << "No Answer" << endl;
			cout << 0 << endl;
		}
	}
	return 0;
}
