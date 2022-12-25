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
    ll n; cin >> n;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    ll q, t1, t2, t3; cin >> q;
    while (q--) {
        cin >> t1 >> t2;
        if (t1 == 1) {
            cin >> t3;
            vec[t2] = t3;
        }
        else
            cout << vec[t2] << endl;
    }
    return 0;
}