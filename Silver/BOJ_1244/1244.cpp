#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N, M;
static vector<int> vc(100);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> vc[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int sex, num;
		cin >> sex >> num;

		if (sex == 1) {
			for (int j = num - 1; j < N; j += num) {
				if (vc[j] == 0) {
					vc[j] = 1;
				}
				else if (vc[j] == 1) {
					vc[j] = 0;
				}
			}
		}
		if (sex == 2) {
			int st = num - 2, ed = num;
			if (vc[num - 1] == 0) {
				vc[num - 1] = 1;
			}
			else if (vc[num - 1] == 1) {
				vc[num - 1] = 0;
			}

			while ((st >=0 && ed < N) && vc[st] == vc[ed]) {
				if (vc[st] == 0) {
					vc[st] = 1;
					vc[ed] = 1;
				}
				else if (vc[st] == 1) {
					vc[st] = 0;
					vc[ed] = 0;
				}
				st--;
				ed++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << vc[i] << " ";
	}
	cout << "\n";

	return 0;
}