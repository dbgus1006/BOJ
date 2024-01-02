#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	while (getline(cin, str)) {
		if (str[0] == '.') {
			break;
		}

		stack<char> st;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '[') {
				st.push(str[i]);
			}
			else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
					continue;
				}
				st.push(str[i]);
				break;
			}
			else if (str[i] == '(') {
				st.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
					continue;
				}
				st.push(str[i]);
				break;
			}
			else if (str[i] == '.') {
				break;
			}
		}

		if (st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}