/*
【题目描述】
在一次考试中，每个学生的成绩都不相同，现知道了每个学生的学号和成绩，求考第k名学生的学号和成绩。

【输入】
第一行有两个整数，分别是学生的人数n（1≤n≤100），和求第k名学生的k（1≤k≤n）。

其后有n行数据，每行包括一个学号（整数）和一个成绩（浮点数），中间用一个空格分隔。

【输出】
输出第k名学生的学号和成绩，中间用空格分隔。（注：请用%g输出成绩）

【输入样例】
5 3
90788001 67.8
90788002 90.3
90788003 61
90788004 68.4
90788005 73.9
【输出样例】
90788004 68.4
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio> 
using namespace std;

struct Student{  
    long id;
	double score; 
    Student(long x, double y) : id(x), score(y) { }  
}; 

int s_cmp(const Student &s1, const Student &s2)
{
	return s1.score > s2.score;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector<Student> ivec;
		long id;
		double score;
		for (int i = 0; i < n; i++)
		{
			cin >> id >> score;
			ivec.push_back(Student(id, score));
		}
		stable_sort(ivec.begin(), ivec.end(), s_cmp);
		cout << ivec[k-1].id << " " << ivec[k-1].score << endl;
	}
	return 0;
}
