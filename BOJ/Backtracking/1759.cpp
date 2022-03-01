/* 암호 만들기 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char al[15];
char code[15];
int L, C;

void Backtrack(int cur, int num, int m, int z)
{
	int i;

	if (num == L)
	{
		if (m > 0 && z > 1)
		{
			for (i = 0; i < L; i++)
				cout << code[i];
			cout << '\n';
		}
	}
		
	else 
	{
		for (i = cur + 1; i < C; i++)
		{
			code[num] = al[i];
			if (al[i] == 'a' || al[i] == 'e' || al[i] == 'i' || al[i] == 'o' || al[i] == 'u')
				Backtrack(i, num + 1, m + 1, z);
			else
				Backtrack(i, num + 1, m, z + 1);
		}
	}
}

int main()
{
	int i;
	cin >> L >> C;
	
	bzero(al, sizeof(al));
	bzero(code, sizeof(code));

	for (i = 0; i < C; i++)
		cin >> al[i];

	sort(al, al + C);

	Backtrack(-1, 0, 0, 0);
}