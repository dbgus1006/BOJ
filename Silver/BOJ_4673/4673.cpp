#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static bool arr[10001] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10000; i++) {
		int num = i + (i / 10000) + (i / 1000 % 10) + (i / 100 % 10) + (i / 10 % 10) + (i % 10);
		
		if (num <= 10000) {
			arr[num] = true;
		}
		if (!arr[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}