#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	string str;
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		vector<char> v;

		for (int j = 0; j < str.length(); j++)
		{
			if (v.empty())
			{
				v.push_back(str[j]);
			}
			else
			{
				if (v.back() == str[j])
				{
					v.pop_back();
				}
				else
				{
					v.push_back(str[j]);
				}
			}
		}

		if (v.empty())
		{
			++cnt;
		}
	}

	cout << cnt << "\n";

	return 0;
}