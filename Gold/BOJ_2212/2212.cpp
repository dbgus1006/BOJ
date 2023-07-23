#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int N, int K, vector<int> v)
{
	int result = 0;

	sort(v.begin(), v.end());

	vector<int> dist;

	for (int j = 0; j < N - 1; j++)
	{
		dist.push_back(abs(v[j] - v[j + 1]));
	}

	sort(dist.begin(), dist.end());

	for (int k = 0; k < N - K; k++)
		result += dist[k];

	return result;
}

int main()
{
	int N = 0;
	int K = 0;

	cin >> N >> K;

	vector<int> v;
	int a;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}



	cout << solution(N, K, v) << "\n";

	return 0;
}