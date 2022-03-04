/* 삼각형 만들기 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return (a > b);
}

int main()
{
	int N, i;

	cin >> N;
	int len[N];
	for (i = 0; i < N; i++)
		cin >> len[i];

	sort(len, len + N, cmp);

	for (i = 0; i < N - 2; i++)
	{
		if (len[i] < len[i + 1] + len[i + 2])
		{
			cout << len[i] + len[i + 1] + len[i + 2];
			return 0;
		}
	}
	cout << -1;
}