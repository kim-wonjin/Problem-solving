/* 단지번호 붙이기 */

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 25

using namespace std;

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

void DFS(int i, int j, int num)
{
	if (visit[i][j] == 0 && map[i][j] == 1)
	{
		visit[i][j] = 1;
		map[i][j] = num;

		if (j < (N - 1) && map[i][j + 1])
			DFS(i, j + 1, num);
		if (j > 0 && map[i][j - 1])
			DFS(i, j - 1, num);
		if (i < (N - 1) && map[i + 1][j])
			DFS(i + 1, j, num);
		if (i > 0 && map[i - 1][j])
			DFS(i - 1, j , num);

	}		
}

int main()
{
	int i, j, num;
	cin >> N;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);  // 숫자 1개씩 끊어서 입력받기
	}
	bzero(visit, sizeof(visit));
	num = 1;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && map[i][j] == 1) //새로운 시작점 
			{
				DFS(i, j, num);
				num++;
			}
		}
	}

	cout << num - 1 << '\n';
	int result[num - 1];
	bzero(result, sizeof(result));

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (map[i][j])
				result[map[i][j] - 1]++;
		}
	}
	sort(result, result + num - 1);

	for (i = 0; i < num - 1; i++)
		cout << result[i] << '\n';
	
	/*
	단지 완성 후 지도 출력

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
}