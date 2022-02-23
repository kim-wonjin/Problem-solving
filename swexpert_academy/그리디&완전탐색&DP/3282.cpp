/* 0/1 Knapsack */
 
#include <iostream>

using namespace std;

struct stuff
{
	int volume;
	int price;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case, N, K, i, j;

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		int optimal[N + 1][K + 1];
		struct stuff stuff[N + 1];

		for (i = 1; i < (N + 1); i++)
			cin >> stuff[i].volume >> stuff[i].price;
		
		for (i = 0; i < (N + 1); i++)  //DP
		{
			for (j = 0; j < (K + 1); j++)
			{
				if (i == 0 || j == 0)
					optimal[i][j] = 0;
				else if (stuff[i].volume > j)
					optimal[i][j] = optimal[i - 1][j];
				else 
					optimal[i][j] = max(optimal[i - 1][j], optimal[i - 1][j - stuff[i].volume] + stuff[i].price);
			}
		}
		cout << '#' << test_case << ' ';
		cout << optimal[N][K] << '\n';
	}
}