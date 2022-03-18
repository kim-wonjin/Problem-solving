/* 최단경로 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int>> adj[300001];
int min[20001];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, K, i, j, a, b;

	cin >> V >> E;
	cin >> K;
	for (i = 0; i < E; i++)
		cin >> a >> adj[a].second >> adj[a].first;

	for (i = 0; i < V + 1; i++)
	{
		for (j = 0; j < V + 1; j++)
			cout << w[i][j] << ' ';
		cout << '\n';
	}
}