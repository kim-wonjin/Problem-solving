/* 접두사 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
	return (a.size()<b.size());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, i;
	string input;
	vector<string>::iterator iter, iter2;

	cin >> N;
	vector <string> str;
	for (i = 0; i < N; i++)
	{
		cin >> input;
		str.push_back(input);
	}

	sort(str.begin(), str.end(), cmp);

	for (iter = str.begin(); iter != str.end(); iter++)
	{
		for (iter2 = iter + 1; iter2 != str.end(); iter2++)
		{
			if ((*iter2).find(*iter) == 0)
			{
				str.erase(iter--);
				break;
			}
		}
	}
	cout << str.size();
}