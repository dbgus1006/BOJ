#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<char, char> tree[26];

void preorder(char node)
{
	if (node != '.')
	{
		cout << node;
		preorder(tree[node - 'A'].first);
		preorder(tree[node - 'A'].second);
	}
}
void inorder(char node)
{
	if (node != '.')
	{
		inorder(tree[node - 'A'].first);
		cout << node;
		inorder(tree[node - 'A'].second);
	}
}
void postorder(char node)
{
	if (node != '.')
	{
		postorder(tree[node - 'A'].first);
		postorder(tree[node - 'A'].second);
		cout << node;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		tree[parent - 'A'].first = left;
		tree[parent - 'A'].second = right;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}