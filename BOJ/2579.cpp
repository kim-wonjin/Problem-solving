/* 계단 오르기 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, i, j;
	cin >> N;
	int dp[N + 1];
	int score[N + 1];
	bzero(dp, sizeof(dp));

	score[0] = 0;
	for (i = 1; i < N + 1; i++)
		cin >> score[i];

	dp[1] = score[1];
	dp[2] = score[1] + score[2];

	for (i = 3; i < N + 1; i++)
		dp[i] = max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];
	cout << dp[N];
}