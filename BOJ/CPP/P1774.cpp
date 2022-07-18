#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define PD pair<double, double>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

struct compare {
    bool operator()(pair<double, ll> a, pair<double, ll> b) {
        auto [distA, idxA] = a;
        auto [distB, idxB] = b;
        return distA > distB;
    }
};

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll n, m; cin >> n >> m;
    double t1, t2;
    cout << fixed;
    cout.precision(2);
    vector<PD> loc(n + 1);
    vector<bool> visited(n + 1, false);

    for (ll i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        loc[i] = make_pair(t1, t2);
    }

    ll con_idx1, con_idx2;
    double ans = 0.0;

    map<ll, set<ll>> mp;
    for (ll i = 1; i <= n; i++) {
        mp[i] = set<ll>();
    }

    for (ll i = 1; i <= m; i++) {
        cin >> con_idx1 >> con_idx2;
        mp[con_idx1].emplace(con_idx2);
        mp[con_idx2].emplace(con_idx1);
    }

    function<void()> prim = [&]() -> void {
        priority_queue<pair<double, ll>, vector<pair<double, ll>>, compare> pq;
        pq.emplace(make_pair(0.0, 1));
        while (!pq.empty()) {
            auto [dist, idx] = pq.top();
            pq.pop();

            if (visited[idx])
                continue;

            visited[idx] = true;
            ans += dist;

            for (ll i = 1; i <= n; i++) {
                if (i == idx)
                    continue;
                auto [x1, y1] = loc[idx]; auto [x2, y2] = loc[i];
                double next_dist;
                if (mp[idx].find(i) != mp[idx].end())
                    next_dist = 0.0;
                else
                    next_dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                pq.emplace(make_pair(next_dist, i));
            }
        }
    };

    prim();
    cout << ans << endl;
    return 0;
}
