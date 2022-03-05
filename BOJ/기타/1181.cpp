/* 단어 정렬 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return (a < b);
	else
		return(a.size() < b.size());
}

int main()
{
	int N, i;

	cin >> N;
	string arr[N];

	for (i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N, cmp);
	
	for (i = 0; i < N; i++)
	{
		if (arr[i].compare(arr[i - 1]) != 0)
			cout << arr[i] << '\n';
	}
}
