#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    vector<ll> vec(101);
    for (int i = 1; i <= 100; i++) {
        vec[i] = i;
    }

    ll n, m, t1, t2;
    cin >> n >> m;
    vector<vector<ll>> graph(101, vector<ll>());
    vector<ll> ans(101, LLONG_MAX);
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
    }

    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        assert(t1 > t2);
        graph[t1].emplace_back(t2);
    }

    vector<ll> delta = {1,2,3,4,5,6};
    ans[1] = 0;

    function<void()> bfs = [&]() -> void {
        queue<ll> q;
        q.emplace(1);

        while (!q.empty()) {
            ll cur = q.front();
            q.pop();

            if (cur == 100)
                return;

            // roll the dice
            for (int i = 0; i < 6; i++) {
                ll next = cur + delta[i];
                if (next > 100)
                    continue;

                if (graph[next].size() == 1) {
                    ans[next] = -1;
                    next = graph[next][0];
                }

                if (ans[next] > ans[cur] + 1) {
                    q.emplace(next);
                    ans[next] = ans[cur] + 1;
                }
            }
        }
    };

    bfs();
    cout << ans[100] << endl;
    return 0;
}
