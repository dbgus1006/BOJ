#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

static vector<string> stu;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;

		cin >> str;

		reverse(str.begin(), str.end());

		stu.push_back(str);
	}

	for (int i = 1; ; i++)
	{
		set <string> s;

		for (int j = 0; j < N; j++)
		{
			s.insert(stu[j].substr(0, i));
		}

		if (s.size() == N)
		{
			cout << i;
			break;
		}
	}

	return 0;
}