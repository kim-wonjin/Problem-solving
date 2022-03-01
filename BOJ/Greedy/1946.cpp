/* 신입 사원 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct applicant
{
	int document;
	int interview;
};

bool cmp(struct applicant a, struct applicant b)
{
	return (a.document < b.document);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, i, j, result, min;
	cin >> T;

	while (T--)
	{
		cin >> N;
		struct applicant a[N];
		result = 1;

		for (i = 0; i < N; i++)
		{
			cin >> a[i].document >> a[i].interview;
		}
		sort(a, a + N, cmp);
		min = a[0].interview;

		for (i = 1; i < N; i++)
		{
			if (min > a[i].interview)
			{
				min = a[i].interview;
				result++;
			}
		}
		cout << result << '\n';

		/*
		cout << '\n';
		for (i = 0; i < N; i++)
		{
			cout << a[i].document << ' ' << a[i].interview << '\n';
		}
		*/
		
	}
}