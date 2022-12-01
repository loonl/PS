#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll tc; cin >> tc;
    ll n, m;
    for (int x = 1; x <= tc; x++) {
        cin >> n >> m;
        ll t1;
        vector<ll> sel(n + 1, 0);
        for (ll i = 0; i < m; i++) {
            cin >> t1;
            sel[t1]++;
        }

        ll st = 0, ed = 2 * max(m, n) + 1;
        ll mid, ans;
        while (st <= ed) {
            mid = (st + ed) / 2;
            ll nokori = 0, hitsuyo = 0;
            for (ll i = 1; i <= n; i++) {
                if (sel[i] <= mid)
                    nokori += (mid - sel[i]) / 2;
                else
                    hitsuyo += sel[i] - mid;
            }

            if (hitsuyo > nokori)
                st = mid + 1;
            else {
                ans = mid;
                ed = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
