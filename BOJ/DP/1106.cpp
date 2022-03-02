/* 호텔 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct City
{
	int cost;
	int value;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int C, N, i, j;

	cin >> C >> N;
	struct City city[N + 1];
	int dp[C + 1][N + 1];
	int min_[C + 1];

	bzero(city, sizeof(city));
	bzero(dp, sizeof(dp));

	for (i = 1; i < N + 1; i++)
		cin >> city[i].cost >> city[i].value;
	
	for (i = 1; i < C + 1; i++)
		dp[i][1] = ceil(((float)i / (float)city[1].value)) * city[1].cost;

	for (i = 1; i < C + 1; i++)
	{
		min_[i] = dp[i][1];
		for (j = 2; j < N + 1; j++)
		{
			if (i <= city[j].value)
				dp[i][j] = min(dp[i][j - 1], city[j].cost);
			else
				dp[i][j] = min(dp[i][j - 1], min_[i - city[j].value] + city[j].cost);
			if (min_[i] > dp[i][j])
				min_[i] = dp[i][j];
		}
	}
	cout << min_[C];
	
	/*
	for (i = 0; i < C + 1; i++)
	{
		for (j = 0; j < N + 1; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	*/
}