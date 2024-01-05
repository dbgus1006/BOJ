#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

static vector<int> vc;
static vector<int> freq(8001);
static vector<int> mFreq;
static int N, sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vc.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> vc[i];
		sum += vc[i];
		if (vc[i] <= 0) {
			freq[abs(vc[i])]++;
		}
		else if (vc[i] > 0) {
			freq[vc[i] + 4000]++;
		}
	}

	sort(vc.begin(), vc.end());

	double am = round((double)sum / (double)N);

	if (am == -0) {
		am = 0;
	}

	cout << am << "\n";

	int max_freq = 0;
	for (int i = 0; i < 8001; i++) {
		max_freq = max(max_freq, freq[i]);
	}

	for (int i = 0; i < 8001; i++) {
		if (freq[i] == max_freq) {
			if (i == 0) {
				mFreq.push_back(i);
			}
			else if (i <= 4000) {
				mFreq.push_back(i * -1);
			}
			else {
				mFreq.push_back(i - 4000);
			}
		}
	}

	sort(mFreq.begin(), mFreq.end(), less<>());

	cout << vc[N / 2] << "\n";

	if (mFreq.size() > 1) {
		cout << mFreq[1] << "\n";
	}
	else {
		cout << mFreq[0] << "\n";
	}

	cout << vc[N - 1] - vc[0] << "\n";

	return 0;
}