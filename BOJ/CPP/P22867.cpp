#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n; cin >> n;
    string t1, t2;
    vector<P> info;
    ll hr, min, sec, ms;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        hr = stoll(t1.substr(0, 2)), min = stoll(t1.substr(3, 2)), sec = stoll(t1.substr(6, 2)), ms = stoll(t1.substr(9, 3));
        info.emplace_back(make_pair(3600000 * hr + 60000 * min + 1000 * sec + ms, 1));
        hr = stoll(t2.substr(0, 2)), min = stoll(t2.substr(3, 2)), sec = stoll(t2.substr(6, 2)), ms = stoll(t2.substr(9, 3));
        info.emplace_back(make_pair(3600000 * hr + 60000 * min + 1000 * sec + ms, 0));
    }

    sort(info.begin(), info.end());
    ll ans = 0, cur = 0;
    for (ll i = 0; i < info.size(); i++) {
        auto [time, code] = info[i];
        if (code == 0)
            cur--;
        else if (code == 1) {
            cur++;
            ans = max(cur, ans);
        }
    }

    cout << ans << endl;
    return 0;
}