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

    ll tc; cin >> tc;
    while (tc--) {
        ll x, y;
        cin >> x >> y;
        y -= x, x = 0;
        if (y <= 3) {
            cout << y << endl;
            continue;
        }

        ll ans = floor(sqrt(y)), maxval = ans;
        y -= ans * ans, ans = (ans - 1) * 2 + 1;
        if (y >= maxval)
            ans += ceil((double)y / maxval);
        else if (y > 0)
            ans++;

        cout << ans << endl;
    }
    return 0;
}