#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

static queue<int> q;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string command;
		getline(cin, command);

		if (command.substr(0, 3) == "pus") {
			q.push(stoi(command.substr(4)));
		}
		else if (command.substr(0, 3) == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (command.substr(0, 3) == "siz") {
			cout << q.size() << "\n";
		}
		else if (command.substr(0, 3) == "emp") {
			cout << q.empty() << "\n";
		}
		else if (command.substr(0, 3) == "fro") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (command.substr(0, 3) == "bac") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}

	return 0;
}