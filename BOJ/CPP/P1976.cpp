#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int> parent;
int find(int x)
{
	if (parent[x] == x)
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	parent[y] = x;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	parent.assign(n + 1, 0);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	int m; cin >> m;

	int t1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> t1;
			if (t1 == 1)
			{
				merge(i, j);
			}
		}
	}

	cin >> t1;
	bool ok = true;
	int pivot = find(t1);
	for (int i = 1; i < m; i++)
	{
		cin >> t1;
		if (pivot != find(t1))
		{
			ok = false;
			break;
		}
	}

	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}