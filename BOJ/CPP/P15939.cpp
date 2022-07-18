#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll n; cin >> n;
	queue<ll> q;
	bool all0 = true;
	ll hap = 0;
	ll ones = 0; ll nj = 0;
	ll x;
	for (ll i = 0; i < n; i++)
	{
		cin >> x;
		if (x != 0)
			all0 = false;
		hap += x;
		if (x == 1)
		{
			ones++;
			nj++;
		}
		else
			q.emplace(x);
	}

	if (all0)
	{
		cout << "YES" << endl;
		exit(0);
	}

	if (hap % 3 != 0)
	{
		cout << "NO" << endl;
		exit(0);
	}

	while (!(q.empty() || ones <= 0))
	{
		auto temp = q.front();
		ll hs = temp / 2;
		ones -= hs;
		if (temp % 2 == 1)
			ones++;
		q.pop();
	}

	if (q.empty() && ones > 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}