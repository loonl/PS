#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--)
	{
		int n, m, t1, t2; cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> t1 >> t2;
		}
		cout << n - 1 << endl;
	}
	return 0;
}