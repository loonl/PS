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
    ll n; cin >> n;
    vector<P> vec(n + 1);

    ll t1, t2;
    for (ll i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        vec[i] = make_pair(t1, t2);
    }

    function<ll(ll, ll, ll, ll)> dist = [&](ll x1, ll y1, ll x2, ll y2) -> ll {
        return abs(x1 - x2) + abs(y1 - y2);
    };

    vector<ll> dist1(n + 1, 0);
    vector<ll> dist2(n + 1, 0);
    for (ll i = 2; i <= n; i++)
        dist1[i] = dist(vec[i - 1].first, vec[i - 1].second, vec[i].first, vec[i].second);

    for (ll i = 3; i <= n; i++)
        dist2[i] = dist1[i - 1] + dist1[i] - dist(vec[i - 2].first, vec[i - 2].second, vec[i].first, vec[i].second);

    ll maxiIDX = -1, val = LLONG_MIN;
    for (ll i = 3; i <= n; i++) {
        if (val < dist2[i]) {
            val = dist2[i];
            maxiIDX = i;
        }
    }

    ll ans = 0;
    for (ll i = 2; i < maxiIDX - 1; i++)
        ans += dist1[i];

    ans += dist(vec[maxiIDX].first, vec[maxiIDX].second, vec[maxiIDX - 2].first, vec[maxiIDX - 2].second);

    for (ll i = maxiIDX + 1; i <= n; i++)
        ans += dist1[i];

    cout << ans << endl;
    return 0;
}