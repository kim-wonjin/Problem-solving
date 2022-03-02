/* Z */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N, r, c;

void recursive(int len, int result, int mark, int y, int x)
{
	int num;
	num = pow(len / 2, 2);

	mark /= 2;

	if (len == 1)
		cout << result;
	else
	{
		if (r < y)
		{
			if (c < x) 
				recursive(len / 2, result, mark,  y - mark, x - mark);  // 2사분면
			else 
				recursive(len / 2, result + (num * 1), mark, y - mark, x + mark);  // 1사분면
		}
		else
		{
			if (c < x)
				recursive(len / 2, result + (num * 2), mark, y + mark, x - mark);  // 3사분면
			else
				recursive(len / 2, result + (num * 3), mark, y + mark, x + mark);  // 4사분면
		}
	}
}

int main()
{
	cin >> N >> r >> c;
	int len = pow(2, N);
	recursive(len, 0, len / 2, len / 2, len / 2);
}