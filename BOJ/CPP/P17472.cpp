#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
vector<vector<ll>> Map;
vector<vector<bool>> visited;
vector<bool> visitedGroup;
ll n, m;
vector<ll> dr = {-1, 1, 0, 0};
vector<ll> dc = {0, 0, -1, 1};
vector<vector<P>> groups;

void renew(ll stR, ll stC, ll num) {
    queue<P> q;
    q.emplace(make_pair(stR, stC));
    visited[stR][stC] = true;

    while (!q.empty()) {
        auto [curR, curC] = q.front();
        q.pop();

        // todo
        Map[curR][curC] = num;
        groups[num].emplace_back(make_pair(curR, curC));

        for (ll i = 0; i < 4; i++) {
            ll nextR = curR + dr[i], nextC = curC + dc[i];
            if (!(nextR < 1 || nextR > n || nextC < 1 || nextC > m)) {
                if (!visited[nextR][nextC] && Map[nextR][nextC] == 1) {
                    visited[nextR][nextC] = true;
                    q.emplace(make_pair(nextR, nextC));
                }
            }
        }
    }
}

void BF(ll stR, ll stC, vector<vector<P>>& graph) {
    ll pivot = Map[stR][stC];

    bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
    ll len1 = 0, len2 = 0, len3 = 0, len4 = 0;

    // left
    ll leftC = stC;
    while (flag1) {
        leftC--;
        if (leftC > 0) {
            if (Map[stR][leftC] == 0) {
                len1++;
                continue;
            }
            else if (Map[stR][leftC] != pivot && len1 >= 2)
                graph[pivot].emplace_back(make_pair(len1, Map[stR][leftC]));

            flag1 = false;
        }
        else
            flag1 = false;
    }

    // right
    ll rightC = stC;
    while (flag2) {
        rightC++;
        if (rightC <= m) {
            if (Map[stR][rightC] == 0) {
                len2++;
                continue;
            }
            else if (Map[stR][rightC] != pivot && len2 >= 2)
                graph[pivot].emplace_back(make_pair(len2, Map[stR][rightC]));

            flag2 = false;
        }
        else
            flag2 = false;
    }

    // up
    ll upR = stR;
    while (flag3) {
        upR++;
        if (upR <= n) {
            if (Map[upR][stC] == 0) {
                len3++;
                continue;
            }
            else if (Map[upR][stC] != pivot && len3 >= 2)
                graph[pivot].emplace_back(make_pair(len3, Map[upR][stC]));
            flag3 = false;
        }
        else
            flag3 = false;
    }

    // down
    ll downR = stR;
    while (flag4) {
        downR--;
        if (downR > 0) {
            if (Map[downR][stC] == 0) {
                len4++;
                continue;
            }
            else if (Map[downR][stC] != pivot && len4 >= 2)
                graph[pivot].emplace_back(make_pair(len4, Map[downR][stC]));
            flag4 = false;
        }
        else
            flag4 = false;
    }
}

void bfs_group(vector<vector<P>>& graph) {
    queue<ll> q;
    q.emplace(1);
    visitedGroup[1] = true;
    while (!q.empty()) {
        ll current = q.front();
        q.pop();

        for (ll i = 0; i < graph[current].size(); i++) {
            auto [dist, next] = graph[current][i];
            if (!visitedGroup[next]) {
                visitedGroup[next] = true;
                q.emplace(next);
            }
        }
    }
}

ll prim(vector<vector<P>>& graph, ll group) {
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(make_pair(0, 1));
    ll cnt = 0, dist = 0;

    while (!pq.empty()) {
        auto [cur$, curL] = pq.top();
        pq.pop();

        if (visitedGroup[curL])
            continue;

        // todo
        visitedGroup[curL] = true;
        dist += cur$;
        cnt++;

        if (cnt == group)
            return dist;

        for (ll i = 0; i < graph[curL].size(); i++) {
            pq.emplace(graph[curL][i]);
        }
    }
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    Map.assign(n + 1, vector<ll>(m + 1, 0));
    visited.assign(n + 1, vector<bool>(m + 1, false));
    groups.assign(7, vector<P>());
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> Map[i][j];
        }
    }

    ll curR = 1, curC = 1;
    ll group = 1;
    while (curR <= n && curC <= m) {
        if (!visited[curR][curC] && Map[curR][curC] == 1) {
            renew(curR, curC, group);
            group++;
        }

        curC++;
        if (curC == m + 1) {
            curR++;
            curC = 1;
        }
    }

    // -1 해야 실제 그룹 수
    group--;
    vector<vector<P>> graph(group + 1, vector<P>());
    visitedGroup.assign(group + 1, false);

    for (ll i = 1; i <= group; i++) {
        for (ll j = 0; j < groups[i].size(); j++) {
            auto [r, c] = groups[i][j];
            BF(r, c, graph);
        }
    }

    bfs_group(graph);
    for (ll i = 1; i <= group; i++) {
        if (!visitedGroup[i]) {
            cout << -1 << endl;
            exit(0);
        }
    }


    visitedGroup.assign(group + 1, false);
    cout << prim(graph, group) << endl;

    return 0;
}
