#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int f_arr[4] = { 2, 3, 5, 7 };
static int arr[5] = { 1, 3, 5, 7, 9 };

int N = 0;

bool isPrime(int ip)
{
	for (int i = 2; i < ip / 2; i++)
	{
		if (ip % i == 0)
			return false;
	}

	return true;
}

void DFS(int v, int t)
{
	if (!isPrime(v))
	{
		return;
	}

	if (t == N)
	{
		cout << v << "\n";
		return;
	}

	++t;
	for (int i : arr)
	{
		DFS(v * 10 + i, t);
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i : f_arr)
	{
		DFS(i, 1);
	}

	return 0;
}