/* 쉬운계단 */

#include <iostream>
#include <cstring>
#define NUM 1000000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, i, j;
	long long result;
	cin >> N;
	long long dp[N + 1][10];

	for (i = 0; i < N + 1; i++)
		bzero(dp[i], sizeof(dp[i]));
	for (i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (i = 2; i < N + 1; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % NUM;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % NUM;
			else
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % NUM;
		}
	}
	
	result = 0;
	for (i = 0; i < 10; i++)
		result += (dp[N][i] % NUM);

	/*
	result %= NUM;	
	cout << result;
	for (i = 0; i < N + 1; i++)
	{
		for(j = 0; j < 10; j++)
		 	cout << dp[i][j] << ' ';
		cout << '\n';
	}
	*/
}