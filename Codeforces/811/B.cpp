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

    ll tc; cin >> tc;
    while (tc--)
    {
        ll n; cin >> n;
        map<ll, ll> counts;
        queue<ll> q;
        ll t1;
        for (ll i = 0; i < n; i++) {
            cin >> t1;
            q.push(t1);
            counts[t1]++;
        }

        set<P> over2;
        for (auto it = counts.begin(); it != counts.end(); it++) {
            if (it->second > 1)
                over2.emplace(make_pair(it->first, it->second));
        }

        ll ans = 0;
        while (!over2.empty()) {
            ll x = q.front();
            q.pop();
            ans++;

            auto found = over2.find(make_pair(x, counts[x]));
            if (found != over2.end()) {
                auto [_x, cnt] = *found;
                over2.erase(found);
                cnt--;
                if (cnt > 1)
                    over2.emplace(make_pair(x, cnt));
            }

            counts[x]--;
        }

        cout << ans << endl;
    }
    return 0;
}
