#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#define ll long long
using namespace std;

static deque<int> dq;
static int T, N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	cin.ignore();

	for (int t = 0; t < T; t++)
	{
		string p;
		getline(cin, p);

		cin >> N;
		cin.ignore();

		string xn;
		getline(cin, xn);

		char str_buffer[500000];
		char* context = nullptr;
		strcpy(str_buffer, xn.c_str());

		// BOJ : strtok_s -> strtok_r
		char* tok = strtok_s(str_buffer, "[,]", &context);
		while (tok != nullptr)
		{
			dq.push_back(stoi(string(tok)));
			tok = strtok_s(nullptr, "[,]", &context);
		}
		

		bool isReverse = false;
		bool isContinue = false;

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (dq.empty())
				{
					continue;
				}

				if (!isReverse)
				{
					isReverse = true;
				}
				else
				{
					isReverse = false;
				}
			}
			else
			{
				if (dq.empty())
				{
					cout << "error\n";
					isContinue = true;
					dq.clear();
					break;
				}

				if (!isReverse)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (isContinue)
		{
			continue;
		}

		cout << "[";
		for (int i = 0; i < dq.size(); i++)
		{
			if (!isReverse)
			{
				cout << dq[i];
			}
			else
			{
				cout << dq[dq.size() - (i + 1)];
			}

			if (i < dq.size() - 1)
			{
				cout << ",";
			}
		}
		cout << "]\n";

		dq.clear();
	}


	return 0;
}