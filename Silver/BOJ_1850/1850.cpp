#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long gcd(long long A, long long B)
{
	if (B == 0)
		return A;

	return gcd(B, A % B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;

	cin >> A >> B;

	long long result = gcd(A, B);

	for (int i = 0; i < result; i++)
		cout << "1";

	return 0;
}