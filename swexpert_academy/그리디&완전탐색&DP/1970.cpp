/* 쉬운 거스름돈 */

#include <iostream>

using namespace std;

int getNum(int N, int bill)
{
	int num;

	num = N / bill;
	cout << num << ' ';
	N -= (bill * num);
	return (N);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case, N;

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cout << '#' << test_case << '\n';
		
		N = getNum(N, 50000);
		N = getNum(N, 10000);
		N = getNum(N, 5000);
		N = getNum(N, 1000);
		N = getNum(N, 500);
		N = getNum(N, 100);
		N = getNum(N, 50);
		N = getNum(N, 10);
		cout << '\n';
	}
}