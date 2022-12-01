#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n; ll t1, ds;
    priority_queue<ll> pq; cin >> ds;
    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    for (ll i = 2; i <= n; i++) {
        cin >> t1;
        pq.emplace(t1);
    }

    ll ans = 0;
    while (pq.top() >= ds) {
        ll temp = pq.top();
        pq.pop();
        ds++;
        ans++;
        temp--;
        pq.emplace(temp);
    }

    cout << ans << endl;
    return 0;
}