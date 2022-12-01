#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e9+7;
bool custom_sort(P a, P b) {
    return abs(a.first) + abs(a.second) > abs(b.first) + abs(b.second);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> plus, minus;
    ll t1, t2;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        plus.emplace_back(t1 + t2);
        minus.emplace_back(t1 - t2);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    cout << max(*plus.rbegin() - plus[0], *minus.rbegin() - minus[0]) << endl;
    return 0;
}
