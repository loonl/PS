#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);


int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    vector<bool> handled(n + 1, false);
    ll ans = 0, ok = 0;
    for (ll i = 1; i <= n; i++) {
        if (!handled[i]) {
            handled[i] = true;

            if (vec[i] == i)
                ok++;
            else {
                if (!handled[vec[i]] && vec[vec[i]] == i) {
                    handled[vec[i]] = true;
                    ans++;
                }
            }
        }
    }

    cout << (ok - 1) * ok / 2 + ans << endl;

    return 0;
}
