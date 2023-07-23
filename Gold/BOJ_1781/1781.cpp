#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int solution(int N, vector<pair<int, int>> v)
{
	int result = 0;
	int deadline = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int j = 0; j < N; j++)
	{
		if (v[j].first > deadline)
		{
			pq.push(v[j].second);
			++deadline;
		}
		else
		{
			if (pq.top() < v[j].second)
			{
				pq.pop();
				pq.push(v[j].second);
			}
		}
	}

	int q_size = pq.size();

	for (int k = 0; k < q_size; k++)
	{
		result += pq.top();
		pq.pop();
	}

	return result;
}

int main()
{
	int N = 0;

	cin >> N;

	vector<pair<int, int>> v;
	int a = 0, b = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	cout << solution(N, v) << "\n";

	return 0;
}