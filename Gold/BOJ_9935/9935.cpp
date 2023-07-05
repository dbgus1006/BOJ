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

	string str, bomb;
	
	cin >> str >> bomb;

	vector<char> v;
	int strl = str.length();
	int boml = bomb.length();
	bool chk = true;

	for (int i = 0; i < strl; i++)
	{
		v.push_back(str[i]);

		if (v.back() == bomb.back())
		{
			for (int j = 0; j < boml; j++)
			{
				if (v[v.size() - boml + j] != bomb[j])
				{
					chk = false;
					break;
				}
			}
			
			if (chk)
			{
				for (int j = 0; j < boml; j++)
				{
					v.pop_back();
				}
			}
			chk = true;
		}
	}

	if (v.empty())
	{
		cout << "FRULA\n";
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
	}

	return 0;
}