#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

ll min(ll a, ll b) {
    if (a > b)
        return b;
    return a;
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll N; cin >> N;
    vector<tuple<ll, ll, ll>> vec;
    vector<multiset<pair<ll, ll>>> graph(N, multiset<pair<ll, ll>>());
    vector<bool> visited(N, false);
    ll t1, t2, t3;

    vector<pair<ll, ll>> Xs;
    vector<pair<ll, ll>> Ys;
    vector<pair<ll, ll>> Zs;

    for (ll i = 0; i < N; i++) {
        cin >> t1 >> t2 >> t3;
        vec.emplace_back(make_tuple(t1, t2, t3));
        Xs.emplace_back(make_pair(t1, i));
        Ys.emplace_back(make_pair(t2, i));
        Zs.emplace_back(make_pair(t3, i));
    }

    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    sort(Zs.begin(), Zs.end());

    // 인접한 친구들만 넣어주기
    for (ll i = 1; i < Xs.size(); i++) {
        // Xs
        ll idx1 = Xs[i - 1].second; ll idx2 = Xs[i].second;
        auto [x1, y1, z1] = vec[idx1]; auto [x2, y2, z2] = vec[idx2];
        ll cost = min(abs(x1 - x2), min(abs(y1 - y2), abs(z1 - z2)));
        graph[idx1].emplace(make_pair(cost, idx2));
        graph[idx2].emplace(make_pair(cost, idx1));

        // Ys
        ll _idx1 = Ys[i - 1].second; ll _idx2 = Ys[i].second;
        auto [_x1, _y1, _z1] = vec[_idx1]; auto [_x2, _y2, _z2] = vec[_idx2];
        ll _cost = min(abs(_x1 - _x2), min(abs(_y1 - _y2), abs(_z1 - _z2)));
        graph[_idx1].emplace(make_pair(_cost, _idx2));
        graph[_idx2].emplace(make_pair(_cost, _idx1));

        // Zs
        ll idx1_ = Zs[i - 1].second; ll idx2_ = Zs[i].second;
        auto [x1_, y1_, z1_] = vec[idx1_]; auto [x2_, y2_, z2_] = vec[idx2_];
        ll cost_ = min(abs(x1_ - x2_), min(abs(y1_ - y2_), abs(z1_ - z2_)));
        graph[idx1_].emplace(make_pair(cost_, idx2_));
        graph[idx2_].emplace(make_pair(cost_, idx1_));
    }

    ll cnt = -1;
    function<ll()> prim = [&]() -> ll {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.emplace(make_pair(0, 0));
        ll total = 0;
        while (!pq.empty()) {
            auto [cur$, current] = pq.top();
            pq.pop();

            if (visited[current])
                continue;

            cnt++;
            visited[current] = true;
            total += cur$;

            if (cnt == N - 1)
                return total;

            for (auto it = graph[current].begin(); it != graph[current].end(); it++) {
                auto [cost, next] = *it;
                pq.emplace(make_pair(cost, next));
            }
        }
    };

    cout << prim() << endl;
    return 0;
}
