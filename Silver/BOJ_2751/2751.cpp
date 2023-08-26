#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N;
static vector<int> v_list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v_list.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v_list[i];
	}

	sort(v_list.begin(), v_list.end());

	for (int i = 0; i < N; i++)
	{
		cout << v_list[i] << "\n";
	}

	return 0;
}