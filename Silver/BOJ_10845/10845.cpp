#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static queue<int> q;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string str;
		getline(cin, str);

		if (str == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << q.back() << "\n";
		}
		else if (str == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			q.push(stoi(str.substr(4, str.size())));
		}
	}

	return 0;
}