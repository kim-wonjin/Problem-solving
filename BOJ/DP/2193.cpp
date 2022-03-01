/* 이친수 */

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, i;

	cin >> N;
	long dp[2][N];

	dp[0][0] = 0;
	dp[1][0] = 1;

	for (i = 1; i < N; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	cout << dp[0][N - 1] + dp[1][N - 1];
}