 /* 새로운 불면증 치료법  */
 
 #include <iostream>
using namespace std;

int main()
{
	int T, test_case, n, init, tmp;
	int result;

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		cout << "#" << test_case << " ";
		init = n;
		result = 0;
		while (result != 1023)
		{	
			tmp = n;
			while (tmp != 0)
			{
				result = result | (1 << (tmp % 10));
				tmp /= 10;
			}
			n += init;
		}
		cout << n - init <<endl;
	}
	return 0;
}