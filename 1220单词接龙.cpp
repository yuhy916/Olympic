/*
【题目描述】
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如beast和astonish，如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。

【输入】
输入的第一行为一个单独的整数n(n≤20)表示单词数，以下n行每行有一个单词（只含有大写或小写字母，长度不超过20），输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。

【输出】
只需输出以此字母开头的最长的“龙”的长度。

【输入样例】
5
at
touch
cheat
choose
tact
a
【输出样例】
23
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

const int N = 30;
int n, b[N] = {0}, maxn = 0;
string s[N], h;

int solve(const string &h) 
{
	for (int i = 1; i <= h.length(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[j] < 2 && s[j].find(h.substr(h.length() - i)) == 0 && (s[j] == h || s[j].find(h) != 0)) 
			{
				string nh(h);
				nh.erase(0, nh.find_first_not_of(" "));
				nh.append(s[j].begin() + i, s[j].end());
				maxn = maxn > nh.length() ? maxn : nh.length();
				
				b[j]++;
				solve(nh);
				b[j]--;
			}
		}
	}
	
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
	}
	cin >> h;
	transform(h.begin(), h.end(), h.begin(), ::tolower);
	solve(" " + h);
	cout << maxn << endl;
	return 0;
}
