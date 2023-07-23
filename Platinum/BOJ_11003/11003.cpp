#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, L = 0;

	cin >> N >> L;

	deque<Node> dq;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (dq.empty())
		{
			dq.push_back(Node(i, num));
			cout << dq.front().second << " ";
			continue;
		}

		if (dq.back().second > num)
		{
			while (dq.back().second > num)
			{
				dq.pop_back();
				if (dq.empty())
					break;
			}
			dq.push_back(Node(i, num));
		}
		else 
		{
			dq.push_back(Node(i, num));
		}

		// Node인덱스가 L범위를 벗어나면 제거
		if (dq.front().first < i - L + 1)
		{
			dq.pop_front();
		}

		cout << dq.front().second << " ";

	}

	

	return 0;
}