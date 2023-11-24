#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N;

void drawStar(int i, int j, int n) {

	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << " ";
	}
	else  if (n / 3 == 0) {
		cout << "*";
	}
	else {
		drawStar(i, j, n / 3);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			drawStar(i, j, N / 3);
		}
		cout << "\n";
	}

	return 0;
}