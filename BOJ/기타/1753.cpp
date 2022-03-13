/* 최단경로 */

#include <iostream>
#include <cstring>

using namespace std;

int w[20001][20001];
int visit[20001];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, K, i, j, a, b;

	bzero(w, sizeof(w));
	bzero(visit, sizeof(visit));
	
	cin >> V >> E;
	cin >> K;
	for (i = 0; i < E; i++)
		cin >> a >> b >> w[a][b];

	for (i = 0; i < V + 1; i++)
	{
		for (j = 0; j < V + 1; j++)
			cout << w[i][j] << ' ';
		cout << '\n';
	}


}