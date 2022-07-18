#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define PD pair<double, ll>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;



int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    cout << fixed;
    cout.precision(3);
    ll cnt = 0;

    ll n; cin >> n;
    vector<PD> inputs; double t1, t2;
    vector<bool> visited(n, false);
    double m = 0.0;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        inputs.emplace_back(make_pair(t1, t2));
    }

    function<void()> bfs = [&]() -> void {
        priority_queue<PD, vector<PD>, greater<PD>> pq;
        pq.emplace(make_pair(0.0, 0));
        while (!pq.empty()) {
            auto [dist, curIDX] = pq.top();
            pq.pop();

            if (visited[curIDX])
                continue;

            visited[curIDX] = true;
            cnt++;
            m += dist;
            if (cnt == n)
                return;

            for (ll i = 0; i < n; i++) {
                if (curIDX == i)
                    continue;
                auto [x1, y1] = inputs[curIDX];
                auto [x2, y2] = inputs[i];
                double next_dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                pq.emplace(make_pair(next_dist, i));
            }
        }
    };

    bfs();
    cout << m <<endl;
    return 0;
}
