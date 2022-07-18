#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll n, k; cin >> n >> k; ll t1;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (ll i = 0; i < n; i++)
	{
		cin >> t1;
		pq.emplace(t1);
	}

	while (k--)
	{
		ll x1 = pq.top(); pq.pop();
		ll x2 = pq.top(); pq.pop();
		pq.emplace(x1 + x2); pq.emplace(x1 + x2);
	}

	ll answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}

	cout << answer << endl;
	return 0;
}