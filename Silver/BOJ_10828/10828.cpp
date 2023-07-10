#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;
	cin.ignore();

	stack<int> st;

	for (int i = 0; i < N; i++)
	{
		string str;

		getline(cin, str);

		if (str == "top")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << "\n";
			}
		}
		else if (str == "size")
		{
			cout << st.size() << "\n";
		}
		else if (str == "empty")
		{
			if (st.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (str == "pop")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else
		{
			st.push(stoi(str.substr(5, str.size() - 5)));
		}
	}

	return 0;
}