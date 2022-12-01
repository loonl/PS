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
    vector<ll> parent(n + 1, -1);
    vector<ll> num(n + 1, MAX);
    vector<vector<P>> graph(n + 1, vector<P>());

    ll t1, t2, t3;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        graph[t1].emplace_back(make_pair(t2, t3));
    }
    ll start, aim; cin >> start >> aim;

    function<void()> dijk = [&]() -> void {
        priority_queue<P, vector<P>, greater<P>> pq;
        num[start] = 0;
        pq.emplace(make_pair(num[start], start));

        while (!pq.empty()) {
            auto [cur$, cur] = pq.top();
            pq.pop();

            if (num[cur] < cur$)
                continue;

            for (ll i = 0; i < graph[cur].size(); i++) {
                auto [next, next$] = graph[cur][i];
                if (num[next] > cur$ + next$) {
                    parent[next] = cur;
                    num[next] = cur$ + next$;
                    pq.emplace(make_pair(num[next], next));
                }
            }
        }
    };

    dijk();
    vector<ll> answers; ll cur = aim;
    while (cur != -1) {
        answers.emplace_back(cur);
        cur = parent[cur];
    }

    cout << num[aim] << endl;
    cout << answers.size() << endl;
    for (auto it = answers.rbegin(); it != answers.rend(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
