#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	string str = to_string(N);

	sort(str.begin(), str.end(), greater<>());

	cout << str << "\n";


	return 0;
}