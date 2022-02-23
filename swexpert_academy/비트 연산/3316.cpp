/* 동아리실 관리하기 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int test_case, T, i, manager, y, t;
	string input;
	long long today[16];
	long long yesterday[16];
	long long result;

	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(yesterday, 0, sizeof(yesterday));
		result = 0;    
		
		cin >> input;
		for (i = 0; i < input.length(); i++)
		{
			memset(today, 0, sizeof(today));
			manager = 1 << (input[i] - 65); // A ascii 65 

			if (i == 0) // 첫째날
			{
				for (y = 1; y < 16; y++)
				{
					if ((manager & y) != 0 && (1 & y) != 0)
						yesterday[y] = 1;
				}
			}
			else
			{
				for (y = 1; y < 16; y++)
				{
					for (t = 1; t < 16; t++)
					{
						if ((manager & t) != 0 && (y & t) != 0)
						{
							today[t] += yesterday[y];
							today[t] %= 1000000007;
						}	
					}
				}
				copy(today, today + 16, yesterday); // 오늘을 어제로 변경
			}
		}
		for (t = 1; t < 16; t++)
		{
			result += today[t];
			result %= 1000000007;
		}
		cout << "#" << test_case << ' ' << result <<endl;
	}
	return 0;
}