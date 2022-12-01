#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++)
            cin >> vec[i][j];
    }

    vector<vector<ll>> pSum(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++)
            pSum[i][j] = pSum[i][j - 1] + pSum[i - 1][j] + vec[i][j] - pSum[i - 1][j - 1];
    }

    ll ans = 0;
    for (ll stR = 1; stR <= n; stR++) {
        for (ll stC = 1; stC <= m; stC++) {
            for (ll edR = stR; edR <= min(n, stR + 10); edR++) {
                for (ll edC = stC; edC <= min(m, stC + 10); edC++) {
                    ll PSUM = pSum[edR][edC] - pSum[edR][stC - 1] - pSum[stR - 1][edC] + pSum[stR - 1][stC - 1];
                    if (PSUM == 10)
                        ans++;
                    if (PSUM >= 10)
                        break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
