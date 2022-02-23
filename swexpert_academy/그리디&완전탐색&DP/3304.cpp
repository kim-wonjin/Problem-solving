/* 최장 공통 부분 수열 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case, asize, bsize, i, j;
	string a, b;
	static int LCS[1001][1001];

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		a = "";
		b = "";
		cin >> a >> b;
		asize = a.size();
		bsize = b.size();

		bzero(LCS, sizeof(LCS));

		for (i = 1; i < asize + 1; i++)
		{
			for (j = 1; j < bsize + 1; j++)
			{
				if (a[i - 1] == b[j - 1])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
				{
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
				}
			}
		}
		cout << '#' << test_case << ' ' << LCS[asize][bsize] << '\n';	
	}
	return 0;
}