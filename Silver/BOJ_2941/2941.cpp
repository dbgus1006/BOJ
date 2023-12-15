#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);

	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1 && str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				i++;
				result++;
				continue;
			}
			else {
				result++;
				continue;
			}
		}
		if (i < str.length() - 2 && str[i] == 'd') {
			if (str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 2;
				result++;
				continue;
			}
		}
		if (i < str.length() - 1 && str[i] == 'd') {
			if (str[i + 1] == '-') {
				i++;
				result++;
				continue;
			}
		}
		if (i < str.length() - 1 && str[i] == 'l') {
			if (str[i + 1] == 'j') {
				i++;
				result++;
				continue;
			}
		}
		if (i < str.length() - 1 && str[i] == 'n') {
			if (str[i + 1] == 'j') {
				i++;
				result++;
				continue;
			}
		}
		if (i < str.length() - 1 && str[i] == 's') {
			if (str[i + 1] == '=') {
				i++;
				result++;
				continue;
			}
		}
		if (i < str.length() - 1 && str[i] == 'z') {
			if (str[i + 1] == '=') {
				i++;
				result++;
				continue;
			}
		}
		result++;
	}

	cout << result;

	return 0;
}