/* 제곱수의 합 */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, S, i;
	double r;

	cin >> N;
	
	long dp[N + 1];
	bzero(dp, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (i = 4; i < N + 1; i++)
	{
		r = sqrt(i);
		S = sqrt(i);
		if (r == (int)r)
			dp[i] = 1;
		else
		{
			dp[i] = dp[S * S] + dp[i - (S * S)];
			while (S != 1)
			{
				S--;
				dp[i] = min(dp[S * S] + dp[i - (S * S)], dp[i]);
			}
		}
	}
	cout << dp[N];
}