#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> vec = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    vector<ll> vec2, vec3;
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        vec2.emplace_back(*it);

    for (ll i = 0; i < vec2.size() - 1; i++)
        vec3.emplace_back((i + 1) * (vec2[i + 1] - vec2[i]));

    ll piv;
    for (ll i = 0; i < vec.size(); i++) {
        if (n / vec[i] > 0) {
            piv = 8 - i;
            break;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < piv; i++)
        ans += vec3[i];

    ans += (piv + 1) * (n - vec2[piv] + 1);
    cout << ans << endl;

    return 0;
}
