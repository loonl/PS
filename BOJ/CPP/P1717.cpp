#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int parent[1000001];
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
	int n, m; cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	int t1, t2, t3;
	while (m--)
	{
		cin >> t1 >> t2 >> t3;
		if (t1 == 0)
			merge(t2, t3);
		else
		{
			if (find(t2) == find(t3))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}

	}
	return 0;
}