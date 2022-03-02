/* 평범한 배낭 */

#include <iostream>
#include <cstring>

using namespace std;

struct info
{
	int weight;
	int value;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K, i, j;
	cin >> N >> K;
	struct info stuff[N + 1];
	int dp[N + 1][K + 1];

	bzero(stuff, sizeof(stuff));
	bzero(dp, sizeof(dp));

	for (i =1; i < N + 1; i++) 
		cin >> stuff[i].weight >> stuff[i].value;
	
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < K + 1; j++)
		{
			if (stuff[i].weight > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuff[i].weight] + stuff[i].value);
		}
	}
	cout << dp[N][K];
}