#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<int> v)
{
	int result = 0;


	for (int i = 0; i < N - 2; i++)
	{
		for (;v[i] > 0;)
		{
			if (v[i + 1] > v[i + 2])
			{
				--v[i], --v[i + 1];
				result += 5;
			}
			else if (v[i] > 0 && v[i + 1] > 0 && v[i + 2] > 0)
			{
				--v[i], --v[i + 1], --v[i + 2];
				result += 7;
			}
			else if (v[i] > 0 && v[i + 1] > 0)
			{
				--v[i], --v[i + 1];
				result += 5;
			}
			else if (v[i] > 0)
			{
				--v[i];
				result += 3;
			}
		}
	}

	if (v[N - 2] > v[N - 1])
	{
		result += (v[N - 1] * 5);
		result += ((v[N - 2] - v[N - 1]) * 3);
	}
	else if (v[N - 2] < v[N - 1])
	{
		result += (v[N - 2] * 5);
		result += ((v[N - 1] - v[N - 2]) * 3);
	}
	else
		result += (v[N - 1] * 5);


	return result;
}

int main()
{
	int N = 0, A = 0;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		v.push_back(A);
	}

	cout << solution(N, v) << "\n";

	return 0;
}