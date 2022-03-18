/* 최단경로 */

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

vector <pair<int, int> > adj[300001];
int min_[20001];

void dijkstra(int start)
{
	int cur, cur_cost, i, next, next_cost;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		cur = pq.top().second;
		cur_cost = -pq.top().first;

		pq.pop();

		if (min_[cur] < cur_cost)
			continue;    // 굳이 인접 노드들을 확인 할 필요가 없는 경우

		for (i = 0; i < adj[cur].size(); i++)
		{
			next = adj[cur][i].second;
			next_cost = cur_cost + adj[cur][i].first;
			if (min_[next] > next_cost)
			{
				min_[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, K, i;
	int start, end, cost;

	cin >> V >> E;
	cin >> K;
	for (i = 1; i < E + 1; i++)
	{
		cin >> start >> end >> cost;
		adj[start].push_back(make_pair(cost, end));
	}

	for (i = 1; i < V + 1; i++)
		min_[i] = INT_MAX;

	min_[K] = 0;
	dijkstra(K);

	for (i = 1; i < V + 1; i++)
	{
		if (min_[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << min_[i] << '\n';
	}
	return 0;
}