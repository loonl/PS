#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false); cout.tie(0)
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
    map<ll, ll> mp;
    ll k;
    vector<ll> vec(n + 1, 0);
    vector<ll> ans(n + 1, 0);
    stack<P> s;
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    for (ll i = 1; i <= n; i++) {
        while (!s.empty()) {
            auto [val, idx] = s.top();
            if (val > vec[i]) {
                ans[i] = idx;
                break;
            }
            s.pop();
        }
        s.emplace(make_pair(vec[i], i));
    }

    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
