#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static vector<int> v_list;
static int N, M, ans = 0, idx;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int num;

		cin >> num;

		v_list.push_back(num);
	}

	sort(v_list.begin(), v_list.end());

	for (int i = 0; i < M; i++)
	{
		if (M - i <= N)
		{
			if (ans < v_list[i] * (M - i))
			{
				ans = v_list[i] * (M - i);
				idx = v_list[i];
			}
		}
		else
		{
			if (ans < v_list[i] * N)
			{
				ans = v_list[i] * N;
				idx = v_list[i];
			}
		}
	}

	cout << idx << " " << ans << "\n";

	return 0;
}