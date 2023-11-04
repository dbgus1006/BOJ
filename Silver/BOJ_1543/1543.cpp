#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string docu, target;
static int res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, docu);
	getline(cin, target);

	if (docu.length() >= target.length())
	{
		for (int i = 0; i < docu.length() - target.length() + 1; i++)
		{
			string comp = docu.substr(i, target.length());

			if (comp == target)
			{
				res++;
				i += target.length() - 1;
			}
		}
	}

	cout << res << "\n";

	return 0;
}