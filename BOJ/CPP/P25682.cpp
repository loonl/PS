#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m, k; cin >> n >> m >> k;
    vector<vector<char>> vec(n + 1, vector<char>(m + 1));
    vector<vector<ll>> pSum1(n + 1, vector<ll>(m + 1, 0)), pSum2(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++)
            cin >> vec[i][j];
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                if (vec[i][j] == 'B') {
                    pSum1[i][j] = pSum1[i][j - 1];
                    pSum2[i][j] = pSum2[i][j - 1] + 1;
                }
                else {
                    pSum1[i][j] = pSum1[i][j - 1] + 1;
                    pSum2[i][j] = pSum2[i][j - 1];
                }
            }
            else {
                if (vec[i][j] == 'B') {
                    pSum1[i][j] = pSum1[i][j - 1] + 1;
                    pSum2[i][j] = pSum2[i][j - 1];
                }
                else {
                    pSum1[i][j] = pSum1[i][j - 1];
                    pSum2[i][j] = pSum2[i][j - 1] + 1;
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            pSum1[i][j] += pSum1[i - 1][j];
            pSum2[i][j] += pSum2[i - 1][j];
        }
    }

    ll ans = MAX;
    for (ll i = k; i <= n; i++) {
        for (ll j = k; j <= m; j++) {
            ll pivot1 = pSum1[i][j] + pSum1[i - k][j - k] - pSum1[i][j - k] - pSum1[i - k][j];
            ans = min(ans, pivot1);

            ll pivot2 = pSum2[i][j] + pSum2[i - k][j - k] - pSum2[i][j - k] - pSum2[i - k][j];
            ans = min(ans, pivot2);
        }
    }

    cout << ans << endl;
    return 0;
}
