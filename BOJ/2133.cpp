/* 타일 채우기 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, i, j;

	cin >> N;
	int dp[N + 1];

	bzero(dp, sizeof(dp));
	dp[0] = 1;
	dp[2] = 3;

	for (i = 4; i < N + 1; i += 2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (j = 0; j <= i - 4; j += 2)
		{
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
}