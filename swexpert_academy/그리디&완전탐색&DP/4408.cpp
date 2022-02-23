/* 자기 방으로 돌아가기 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case, N, i, j, start, dest;
	int hallway[200];

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		bzero(hallway, sizeof(hallway));
		cin >> N; //the number of students

		for (i = 0; i < N; i++)
		{
			cin >> start >> dest;

			if (start > dest)
				swap(start, dest);

			if (start & 1) 
				start++;
			if (dest & 1)
				dest++;

			start /= 2;
			dest /= 2;

			for (j = start; j <= dest; j++)
				hallway[j]++;
		}

		cout << '#' << test_case << ' ';
		cout << *max_element(hallway, hallway + 200) << '\n';
	}
}