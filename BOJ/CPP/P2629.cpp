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
    vector<ll> vec(n, 0);
    ll s = 0;
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
        s += vec[i];
    }

    vector<vector<bool>> Dp(n + 1, vector<bool>(s + 1, false));

    function<void(ll, ll)> dp = [&](ll idx, ll weight) -> void {
        if (idx > n)
            return;

        if (Dp[idx][weight])
            return;

        Dp[idx][weight] = true;
        dp(idx + 1, weight);
        dp(idx + 1, vec[idx] + weight);
        dp(idx + 1, abs(weight - vec[idx]));
    };

    dp(0, 0);

    ll tc; cin >> tc; ll t1;
    while (tc--) {
        cin >> t1;
        if (t1 > s)
            cout << "N ";

        else {
            if (Dp[n][t1])
                cout << "Y ";
            else
                cout << "N ";
        }
    }

    return 0;
}
