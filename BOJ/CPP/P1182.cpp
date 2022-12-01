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

    ll n, s; cin >> n >> s;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1 ; i <= n; i++)
        cin >> vec[i];

    ll count = 0;
    function<void(ll, ll, bool)> back_track = [&](ll idx, ll sum, bool ok) -> void {
        if (idx > n)
            return;

        if (ok) {
            sum += vec[idx];
            if (sum == s)
                count++;
        }

        back_track(idx + 1, sum, true);
        back_track(idx + 1, sum, false);
    };

    back_track(1, 0, true);
    back_track(1, 0, false);
    cout << count << endl;
    return 0;
}
