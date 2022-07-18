#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
#define MAX 1000001
typedef long long ll;

vector<int> inorder(MAX);
vector<int> postorder(MAX);
vector<int> pos(MAX);
int n;

void sol(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end)
		return;

	int root = postorder[post_end];
	cout << root << " ";
	int p = pos[root];
	int left = p - in_start;
	sol(in_start, p - 1, post_start, post_start + left - 1);
	sol(p + 1, in_end, post_start + left, post_end - 1);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}

	for (int i = 0; i < n; i++)
	{
		pos[inorder[i]] = i;
	}

	sol(0, n - 1, 0, n - 1);
	return 0;
}