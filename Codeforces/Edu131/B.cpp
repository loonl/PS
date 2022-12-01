#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
//typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll tc; cin >> tc;
    ll n;
    while (tc--) {
        cin >> n;
        vector<bool> used(n + 1, false);
        vector<ll> bs(n + 1, 0);
        cout << 2 << endl;
        for (ll start = 1; start <= n / 2; start += 2) {
            for (ll i = start; i <= n; i *= 2) {
                if (!used[i]) {
                    cout << i << " ";
                    used[i] = true;
                }
            }
        }

        for (ll i = 1; i <= n; i++) {
            if (!used[i]) {
                cout << i << " ";
                used[i] = true;
            }
        }
    }
    return 0;
}
