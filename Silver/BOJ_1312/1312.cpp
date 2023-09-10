#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

static int A, B, N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> N;

	for (int i = 0; i < N; i++)
	{
		A = (A % B) * 10;
	}

	cout << A / B << "\n";

	return 0;
}