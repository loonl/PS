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

    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
    vector<P> house, chicken;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1)
                house.emplace_back(make_pair(i, j));
            else if (vec[i][j] == 2)
                chicken.emplace_back(make_pair(i, j));
        }
    }

    ll ans = MAX; vector<ll> selected;
    function<void(ll, ll, bool)> back_track = [&](ll count, ll idx, bool use) -> void {
        if (idx > chicken.size())
            return;

        if (count == m) {
            vector<ll> dist(house.size(), MAX);
            for (ll i = 0; i < house.size(); i++) {
                auto [houR, houC] = house[i];
                for (ll j = 0; j < selected.size(); j++) {
                    auto [chiR, chiC] = chicken[selected[j]];
                    ll temp = abs(houR - chiR) + abs(houC - chiC);
                    if (temp < dist[i])
                        dist[i] = temp;
                }
            }

            ll temp = 0;
            for (ll i = 0; i < house.size(); i++)
                temp += dist[i];

            if (ans > temp)
                ans = temp;
            return;
        }

        if (use) {
            selected.emplace_back(idx);
            back_track(count + 1, idx + 1, true);
            back_track(count + 1, idx + 1, false);
            selected.pop_back();
        }
        else {
            back_track(count, idx + 1, true);
            back_track(count, idx + 1, false);
        }
    };

    back_track(0, 0, true);
    back_track(0, 0, false);
    cout << ans << endl;
    return 0;
}
