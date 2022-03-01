/* 가장 큰 정사각형 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int n, m, i, j,result;

	cin >> n >> m;
	int map[n + 1][m + 1];
	int dp[n + 1][m + 1];
	
	bzero(dp, sizeof(map));
	bzero(dp, sizeof(dp));
	result = 0;

	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < m + 1; j++)
			scanf("%1d", &map[i][j]);
	}

	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < m + 1; j++)
		{
			if (map[i][j])
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;	
			if (result < dp[i][j])
				result = dp[i][j];	
		}
	}
	cout << pow(result, 2);
	
	/*
	cout << '\n';
	for (i = 0; i < n + 1; i++)
	{
		for (j = 0; j < m + 1; j++)
			cout << dp[i][j];
		cout << '\n';
	}
	*/
}
