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
    while (tc--) {
        ll n, m, t; cin >> n >> m >> t;
        ll s, g, h; cin >> s >> g >> h;
        vector<vector<P>> graph(n + 1, vector<P>());

        ll t1, t2, t3;
        for (ll i = 0; i < m; i++) {
            cin >> t1 >> t2 >> t3;
            graph[t1].emplace_back(make_pair(t3, t2));
            graph[t2].emplace_back(make_pair(t3, t1));
        }

        vector<ll> if_ans(t + 1, 0);
        for (ll i = 1; i <= t; i++) {
            cin >> if_ans[i];
        }

        vector<pair<ll, bool>> info(n + 1, make_pair(LLONG_MAX, false));

        function<void(ll)> bfs = [&](ll start) -> void {
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.emplace(make_pair(0, start));
            ll lastL = start;

            while (!pq.empty()) {
                auto [curD, curL] = pq.top();
                pq.pop();

                for (ll i = 0; i < graph[curL].size(); i++) {
                    auto [nextD, nextL] = graph[curL][i];

                    if (info[nextL].first > nextD + curD || (info[nextL].first == nextD + curD && (!info[nextL].second))) {
                        bool ok = info[curL].second;
                        if ((curL == g && nextL == h) || (curL == h && nextL == g))
                            ok = true;

                        info[nextL] = make_pair(curD + nextD, ok);
                        pq.emplace(curD + nextD, nextL);
                    }
                }
            }
        };

        bfs(s);

        sort(if_ans.begin(), if_ans.end());
        for (ll i = 1; i <= t; i++) {
            auto [dist, ok] = info[if_ans[i]];
            if (ok)
                cout << if_ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
