#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
typedef double d;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main() {
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll a, b; cin >> a >> b;
    ll ans = 1;
    for (ll i = 0; i < b; i++)
        ans *= a;
    cout << ans << endl;
    return 0;
}