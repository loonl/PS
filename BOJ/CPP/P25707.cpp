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

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    ll ans = 0;
    sort(vec.begin(), vec.end(), greater<>());
    ll pivot1 = vec[0], pivot2 = vec[1];
    ans += pivot1 - pivot2;
    for (ll i = 2; i < n; i++) {
        ans += pivot1 - vec[i];
        pivot1 = vec[i];
    }

    ans += pivot2 - pivot1;
    cout << ans << endl;
    return 0;
}
