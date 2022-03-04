/* 스타트와 링크 */

#include <iostream>
#include <cstring>

using namespace std;

struct man
{
	int s[21];
	char team;
};

struct man man[21];
int N, teamS, teamL, result;

void calculate()
{
	int i, j;
	for (i = 1; i < N + 1; i++)
	{
		for (j = i + 1; j < N + 1; j++)
		{
			if (man[i].team == man[j].team && man[i].team == 's')
				teamS += (man[i].s[j] + man[j].s[i]);
			else if (man[i].team == man[j].team && man[i].team == 'l')
				teamL += (man[i].s[j] + man[j].s[i]);
		}
	}
		if (abs(teamS - teamL) < result)
			result = abs(teamS - teamL);
}

void Backtrack(int cur, int num)
{
	int i;

	if (num == N / 2)
	{
		calculate();
		teamS = 0;
		teamL = 0;
	}
	else
	{
		for (i = cur; i < N + 1; i++)
		{
			man[i].team = 's';
			Backtrack(i + 1, num + 1);
			man[i].team = 'l';
		}
	}
}

int main()
{
	int i, j;
	cin >> N;

	result = INT_MAX;
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < N + 1; j++)
		{
			cin >> man[i].s[j];
		}
	}
	for (i = 1; i < N + 1; i++)
		man[i].team = 'l';

	Backtrack(1, 0);
	cout << result;
}