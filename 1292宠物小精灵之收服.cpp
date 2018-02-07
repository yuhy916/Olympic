/*
【题目描述】
宠物小精灵是一部讲述小智和他的搭档皮卡丘一起冒险的故事。

一天，小智和皮卡丘来到了小精灵狩猎场，里面有很多珍贵的野生宠物小精灵。小智也想收服其中的一些小精灵。然而，野生的小精灵并不那么容易被收服。对于每一个野生小精灵而言，小智可能需要使用很多个精灵球才能收服它，而在收服过程中，野生小精灵也会对皮卡丘造成一定的伤害（从而减少皮卡丘的体力）。当皮卡丘的体力小于等于0时，小智就必须结束狩猎（因为他需要给皮卡丘疗伤），而使得皮卡丘体力小于等于0的野生小精灵也不会被小智收服。当小智的精灵球用完时，狩猎也宣告结束。

我们假设小智遇到野生小精灵时有两个选择：收服它，或者离开它。如果小智选择了收服，那么一定会扔出能够收服该小精灵的精灵球，而皮卡丘也一定会受到相应的伤害；如果选择离开它，那么小智不会损失精灵球，皮卡丘也不会损失体力。

小智的目标有两个：主要目标是收服尽可能多的野生小精灵；如果可以收服的小精灵数量一样，小智希望皮卡丘受到的伤害越小（剩余体力越大），因为他们还要继续冒险。

现在已知小智的精灵球数量和皮卡丘的初始体力，已知每一个小精灵需要的用于收服的精灵球数目和它在被收服过程中会对皮卡丘造成的伤害数目。请问，小智该如何选择收服哪些小精灵以达到他的目标呢？

【输入】
输入数据的第一行包含三个整数：N(0<N<1000)，M(0<M<500)，K(0<K<100)，分别代表小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量。

之后的K行，每一行代表一个野生小精灵，包括两个整数：收服该小精灵需要的精灵球的数量，以及收服过程中对皮卡丘造成的伤害。

【输出】
输出为一行，包含两个整数：C，R，分别表示最多收服C个小精灵，以及收服C个小精灵时皮卡丘的剩余体力值最多为R。

【输入样例】
10 100 5
7 10
2 40
2 50
1 20
4 20
【输出样例】
3 30
【提示】
样例输入2：

10 100 5

8 110

12 10

20 10

5 200

1 110

样例输出2：

0 100

提示:

对于样例输入1：小智选择：(7,10) (2,40) (1,20) 这样小智一共收服了3个小精灵，皮卡丘受到了70点伤害，剩余100-70=30点体力。所以输出3 30。

对于样例输入2：小智一个小精灵都没法收服，皮卡丘也不会收到任何伤害，所以输出0 100。
*/
#include <iostream>
using namespace std;

const int N = 1010, M = 510, K = 110; 

int n, m, k;
int u[K], d[K], dp[N][M];

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
		cin >> u[i] >> d[i];

	for (int i = 1; i <= k; i++)
		for (int j = n; j >= u[i]; j--)
			for (int z = m; z >= d[i]; z--)
				dp[j][z] = max(dp[j][z], dp[j-u[i]][z-d[i]] + 1);
	
	cout << dp[n][m] << " ";
	
	for (int i = n; i >= 0; i++)
		for (int j = 0; j <= m; j++)
			if (dp[i][j] == dp[n][m])
			{
				cout << m-j << endl;
				return 0;
			}
		
	return 0;
} 
