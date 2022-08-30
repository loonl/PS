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
    ll x;
    vector<ll> vec;
    vector<ll> orig(n , 0);
    vector<ll> dp(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> orig[i];
        auto found = lower_bound(vec.begin(), vec.end(), orig[i]);
        if (found == vec.end()) {
            vec.emplace_back(orig[i]);
            dp[i] = vec.size();
        }
        else {
            ll idx = found - vec.begin() + 1;
            vec[idx - 1] = orig[i];
            dp[i] = idx;
        }
    }

    cout << vec.size() << endl;
    ll pivot = vec.size();
    vector<ll> ans;
    for (ll i = n - 1; i >= 0; i--) {
        if (pivot == 0)
            break;

        if (dp[i] == pivot) {
            pivot--;
            ans.emplace_back(orig[i]);
        }
        else {
            if (ans.size() >= 2) {
                if (pivot + 1 == dp[i] && ans[ans.size() - 1] < orig[i] && ans[ans.size() - 2] > orig[i])
                    ans[ans.size() - 1] = orig[i];
            }
            else if (ans.size() == 1) {
                if (pivot + 1 == dp[i] && ans[0] < orig[i])
                    ans[0] = orig[i];
            }
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
