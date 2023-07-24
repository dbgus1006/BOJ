#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
static int calc[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			calc[i][j] = (i + j) % 10;
		}
	}

	string s1, s2;
	cin >> s1 >> s2;

	vector<int> v;

	for (int i = 0; i < s1.size(); i++)
	{
		v.push_back(arr[s1[i] - 65]);
		v.push_back(arr[s2[i] - 65]);
	}

	for (int i = v.size(); i > 2; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			v[j] = calc[v[j]][v[j + 1]];
		}
	}

	cout << v[0] << v[1];

	return 0;
}