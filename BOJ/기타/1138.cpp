/* 한줄로 서기 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, i, j, count;

	cin >> N;
	int memo[N];
	int order[N];

	for (i = 0; i < N; i++)
		cin >> memo[i];
	
	bzero(order, sizeof(order));

	for (i = 0; i < N; i++)
	{
		j = 0;
		count = 0;
		while (1)
		{
			if (count == memo[i] && order[j] == 0)
				break;
			if (order[j] == 0)
				count++;
			j++;
		}
		order[j] = i + 1;
	}

	for (i = 0; i < N; i++)
	{
		cout << order[i] <<' ';
	}
}