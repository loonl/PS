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
    ll start, aim; cin >> start >> aim;
    vector<bool> visited(100001, false);
    vector<ll> parent(100001, -1);

    function<void()> bfs = [&]() -> void {
        visited[start] = true;
        queue<P> q;
        q.emplace(make_pair(start, -1));

        while (!q.empty()) {
            auto [cur, prev] = q.front();
            q.pop();

            if (prev != -1)
                parent[cur] = prev;

            if (cur == aim)
                return;

            ll next;
            next = cur - 1;
            if (next >= 0) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(make_pair(next, cur));
                }
            }

            next = cur + 1;
            if (next <= 100000) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(make_pair(next, cur));
                }
            }

            next = 2 * cur;
            if (next <= 100000) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(make_pair(next, cur));
                }
            }
        }
    };

    bfs();
    vector<ll> answers;
    ll cur = aim;
    while (cur != -1) {
        answers.emplace_back(cur);
        cur = parent[cur];
    }

    cout << answers.size() - 1 << endl;
    for (auto it = answers.rbegin(); it != answers.rend(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
