#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<int> vc;
static vector<int> vb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int c;

		cin >> c;

		vc.push_back(c);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int b;

		cin >> b;

		vb.push_back(b);
	}

	sort(vc.rbegin(), vc.rend());
	sort(vb.rbegin(), vb.rend());

	if (vb[0] > vc[0])
	{
		cout << "-1";
		return 0;
	}

	int result = 0;

	while (!vb.empty())
	{
		result++;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < vb.size(); j++)
			{
				if (vc[i] >= vb[j])
				{
					vb.erase(vb.begin() + j);
					break;
				}
			}
		}
	}
	
	cout << result << "\n";

	return 0;
}