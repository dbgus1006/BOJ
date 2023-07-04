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

	string str;

	cin >> str;

	vector<char> v;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 65)
		{
			if (str[i] == '(')
			{
				v.push_back(str[i]);
			}
			else if (str[i] == ')')
			{
				while (v.back() != '(')
				{
					cout << v.back();
					v.pop_back();
				}
				v.pop_back();
			}
			else
			{
				if (!v.empty())
				{
					if (str[i] == '*' || str[i] == '/')
					{
						while (v.back() == '*' || v.back() == '/')
						{
							cout << v.back();
							v.pop_back();
						}
						v.push_back(str[i]);
					}
					else if (str[i] == '+' || str[i] == '-')
					{
						while (!v.empty() && v.back() != '(')
						{
							cout << v.back();
							v.pop_back();
						}
						v.push_back(str[i]);
					}
				}
				else
				{
					v.push_back(str[i]);
				}
			}
		}
		else
		{
			cout << str[i];
		}
	}

	while (!v.empty())
	{
		cout << v.back();
		v.pop_back();
	}

	return 0;
}