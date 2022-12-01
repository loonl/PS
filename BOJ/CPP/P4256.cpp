#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        vector<ll> pre(n + 1, 0), in(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> pre[i];

        for (ll i = 1; i <= n; i++)
            cin >> in[i];

        ll count = 1;
        function<void(ll, ll)> post = [&](ll left, ll right) -> void {
            if (left > right)
                return;

            ll idx;
            for (ll i = left; i <= right; i++) {
                if (pre[count] == in[i]) {
                    idx = i;
                    count++;
                    break;
                }
            }

            post(left, idx - 1);
            post(idx + 1, right);
            cout << in[idx] << " ";
        };


        post(1, n);
        cout << endl;
    }

    return 0;
}
