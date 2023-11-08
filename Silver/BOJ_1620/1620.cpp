#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> map1;
unordered_map<string, string> map2;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin.ignore();

	for (int i = 1; i <= N; i++)
	{
		string name;
		getline(cin, name);
		map1.insert(make_pair(to_string(i), name));
		map2.insert(make_pair(name, to_string(i)));
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		getline(cin, str);
		if (map1.count(str))
		{
			cout << map1[str] << "\n";
		}
		if (map2.count(str))
		{
			cout << map2[str] << "\n";
		}
	}

	return 0;
}