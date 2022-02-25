/* DFS와 BFS */

#include <iostream>
#include <cstring>
#include <queue>
# define MAXN 1000

using namespace std;

int N, M;
int map[MAXN + 1][MAXN + 1];
int visit[MAXN + 1];

void DFS(int cur)
{
	int i;

	cout << cur << ' ';
	visit[cur] = 1;
	for (i = 1; i < N + 1; i++)
	{
		if (map[cur][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}

void BFS(int cur)
{
	int i;
	queue <int> q;
	q.push(cur);
	visit[cur] = 1;
	cout << cur << ' ';
	
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (i = 0; i < N + 1; i++)
		{
			if (visit[i] == 0 && map[cur][i] == 1)
			{
				q.push(i);
				visit[i] = 1;
				cout << i << ' ';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int	V, i, v1, v2;

	bzero(map, sizeof(map));
	cin >> N >> M >> V;
	for (i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}
	bzero(visit, sizeof(visit));
	DFS(V);
	cout << '\n';
	bzero(visit, sizeof(visit));
	BFS(V);
}