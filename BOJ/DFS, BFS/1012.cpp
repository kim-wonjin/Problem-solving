/* 유기농 배추 */

#include <iostream>
#include <cstring>

using namespace std;
int map[2500][2500];
int visit[2500][2500];
int N, M;

void DFS(int i, int j)
{
	if (visit[i][j] == 0)
	{
		visit[i][j] = 1;
		
		if (j < N - 1 && map[i][j + 1] == 1)
			DFS(i, j + 1);
		if (j > 0 && map[i][j - 1] == 1)
			DFS(i, j - 1);
		if (i < M - 1 && map[i + 1][j] == 1)
			DFS(i + 1, j);
		if (i > 0 && map[i - 1][j] == 1)
			DFS(i - 1, j);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int K, i, j, a, b, result;

		cin >> N >> M >> K;
		
		bzero(map, sizeof(map));
		bzero(visit, sizeof(visit));
		for (i = 0; i < K; i++)
		{
			cin >> a >> b;
			map[b][a] = 1;
		}
		result = 0;
		
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (map[i][j] == 1 && visit[i][j] == 0)
				{
					DFS(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';

		/*
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
				cout << map[i][j] << ' ';
			cout << '\n';
		}
		*/
	}
}