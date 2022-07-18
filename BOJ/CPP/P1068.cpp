#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll n; cin >> n;
    vector<vector<ll>> graph(n, vector<ll>());
    vector<bool> visited(n, false);
    vector<ll> parents(n, 0);

    ll t1, topmost;
    for (int i = 0; i < n; i++) {
        cin >> parents[i];
        if (parents[i] == -1) {
            topmost = i;
            continue;
        }

        graph[parents[i]].emplace_back(i);
    }

    ll killed; cin >> killed;
    ll answer = 0;

    function<void(ll)> dfs = [&](ll current) -> void {
        visited[current] = true;

        if (graph[current].size() == 0) {
            answer++;
            return;
        }

        for (auto next : graph[current]) {
            if (!visited[next] && next != killed)
                dfs(next);
        }
        if (graph[current].size() == 1 && graph[current][0] == killed) {
            answer++;
            return;
        }
    };

    if (topmost != killed)
        dfs(topmost);

    cout << answer << endl;
    return 0;
}
