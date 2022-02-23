/* 최대 상금 */

#include <iostream>
#include <cstring>

using namespace std;

string reward;
int num, result;

void dfs(int index, int num)
{
	int i, j;
    if(num == 0)
    {
        result = max(result, stoi(reward));
        return;
    }
    for(i = index; i < reward.size() - 1; i++)
    {
        for(j = i + 1; j < reward.size(); j++)
        {
            swap(reward[i], reward[j]);
            dfs(i, num - 1);
            swap(reward[i], reward[j]);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case;

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; test_case++)
	{
		reward = "";
		result = 0;
		cin >> reward >> num;
		
		if(num > reward.size())
            num = reward.size();
        dfs(0, num);
        cout << "#" << test_case << " " << result << '\n';	
	}
}