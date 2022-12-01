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
    ll n, m, t1, t2; cin >> n >> m;
    vector<ll> vec1, vec2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        vec1.emplace_back(t1);
        vec2.emplace_back(t2);
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    ll ans = 0;
    if (vec1[0] / 6.0 > vec2[0]) {
        ans += vec2[0] * n;
        cout << ans << endl;
        exit(0);
    }

    while (n / 6 > 0) {
        ans += vec1[0];
        n -= 6;
    }

    ans += min(vec2[0] * n, vec1[0]);
    cout << ans << endl;
    return 0;
}