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
    ll n, m; cin >> n >> m;
    vector<vector<bool>> vec(n + 1, vector<bool>(m + 1, false));
    char t1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> t1;
            if (t1 == 'o')
                vec[i][j] = true;
            else
                vec[i][j] = false;
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            vector<bool> ok(m + 1, false);
            for (ll k = 1; k <= m; k++) {
                if (vec[i][k] || vec[j][k])
                    ok[k] = true;
            }

            bool allOk = true;
            for (ll i = 1; i <= m; i++) {
                if (!ok[i]) {
                    allOk = false;
                    break;
                }
            }

            if (allOk)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}