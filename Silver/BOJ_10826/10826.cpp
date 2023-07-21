#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static string pibo[10001];
static vector<int> v1, v2;

string big_number_sum(string s1, string s2)
{
	v1.push_back(0);
	v2.push_back(0);

	for (int i = 0; i < s1.size() - s2.size(); i++)
	{
		v2.push_back(0);
	}

	for (int i = 0; i < s1.size(); i++)
	{
		v1.push_back(s1[i] - '0');
	}
	for (int i = 0; i < s2.size(); i++)
	{
		v2.push_back(s2[i] - '0');
	}

	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++)
	{
		int sum = v1[i] + v2[i];

		if (sum >= 10)
		{
			v1[i + 1]++;
			sum -= 10;
		}

		v1[i] = sum;
	}

	reverse(v1.begin(), v1.end());

	string str;

	if (v1[0] == 1)
	{
		str.push_back('1');
	}

	for (int i = 1; i < v1.size(); i++)
	{
		str.push_back(v1[i] + '0');
	}

	v1.clear();
	v2.clear();

	return str;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	pibo[0] = "0";
	pibo[1] = "1";

	for (int i = 2; i <= n; i++)
	{
		pibo[i] = big_number_sum(pibo[i - 1], pibo[i - 2]);
	}

	cout << pibo[n];

	return 0;
}