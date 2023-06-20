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

	int temp = 0;
	int cnt = 1;
	vector<int> vint;
	vector<char> vchar;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48)
		{
			if (cnt == 1)
			{
				temp = str[i] - 48;
			}
			else
			{
				temp = temp * 10 + (str[i] - 48);
			}
			cnt++;
		}
		else
		{
			vint.push_back(temp);
			temp = 0;
			cnt = 1;
			vchar.push_back(str[i]);
		}
	}
	vint.push_back(temp);

	int min = 0;
	int result = vint[0];

	for (int i = 0; i < vint.size() - 1;)
	{
		if (i < vint.size() - 2 && vchar[i] == '-' && vchar[i + 1] == '+')
		{
			min += vint[i + 1];
			i++;

			while (vchar[i] == '+')
			{
				min += vint[i + 1];
				i++;

				if (i == vint.size() - 1)
					break;
			}

			result -= min;
			min = 0;
		}
		else if (vchar[i] == '-')
		{
			result -= vint[i + 1];
			i++;
		}
		else if (vchar[i] == '+')
		{
			result += vint[i + 1];
			i++;
		}
	}

	cout << result << "\n";

	return 0;
}