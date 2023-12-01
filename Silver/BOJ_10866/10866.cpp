#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
using namespace std;

static deque<int> dq;
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
			if (command.substr(5, 1) == "f") {
				dq.push_front(stoi(command.substr(11)));
			}
			else if (command.substr(5, 1) == "b") {
				dq.push_back(stoi(command.substr(10)));
			}
		}
		else if (command.substr(0, 3) == "pop") {
			if (command.substr(4, 1) == "f") {
				if (dq.empty()) {
					cout << "-1\n";
					continue;
				}
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else if (command.substr(4, 1) == "b") {
				if (dq.empty()) {
					cout << "-1\n";
					continue;
				}
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (command.substr(0, 3) == "siz") {
			cout << dq.size() << "\n";
		}
		else if (command.substr(0, 3) == "emp") {
			cout << dq.empty() << "\n";
		}
		else if (command.substr(0, 3) == "fro") {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
		}
		else if (command.substr(0, 3) == "bac") {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
		}
	}

	return 0;
}