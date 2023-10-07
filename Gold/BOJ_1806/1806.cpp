#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

static vector<int> v;
static int N, S, res_min = INF;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int st = 0, ed = 0;
	int sum = 0;

	while (st <= ed)
	{
		if (sum >= S)
		{
			res_min = min(res_min, ed - st);

			sum -= v[st];
			st++;
		}
		else if (ed == N)
		{
			break;
		}
		else
		{
			sum += v[ed];
			ed++;
		}
	}

	if (res_min == INF)
	{
		cout << "0\n";
	}
	else
	{
		cout << res_min << "\n";
	}

	return 0;
}