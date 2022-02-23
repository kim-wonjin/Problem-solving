/* 이진수 표현 */

#include <iostream>
#include <cmath>  //pow

using namespace std;

int main()
{
	int test_case;
	int T, n, m, check;

	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		check = pow(2, n) - 1;
		cout << "#" << test_case << ' ';
		if ((check & m)== check)
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;
	}
	return 0;
}