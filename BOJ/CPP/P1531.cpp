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
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(101, vector<ll>(101, 0));

    ll t1, t2, t3, t4;
    while (n--) {
        cin >> t1 >> t2 >> t3 >> t4;
        for (ll i = t1; i <= t3; i++) {
            for (ll j = t2; j <= t4; j++)
                vec[i][j]++;
        }
    }

    ll invisible = 0;
    for (ll i = 1; i <= 100; i++) {
        for (ll j = 1; j <= 100; j++) {
            if (vec[i][j] > m)
                invisible++;
        }
    }

    cout << invisible << endl;
    return 0;
}