#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
ll MOD = pow(10, 9) + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    ll stR, stC, edR, edC; cin >> stR >> stC >> edR >> edC;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    vector<ll> dr = {-2, -2, 0, 0, 2, 2};
    vector<ll> dc = {-1, 1, -2 ,2, -1, 1};

    function<ll()> bfs = [&]() -> ll {
        visited[stR][stC] = true;
        queue<T> q;
        q.emplace(make_tuple(stR, stC, 0));

        while (!q.empty()) {
            auto [curR, curC, curNum] = q.front();
            q.pop();

            if (curR == edR && curC == edC)
                return curNum;

            for (ll i = 0; i < 6; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];

                if (!(nextR < 0 || nextC < 0 || nextR > n || nextC > n)) {
                    if (!visited[nextR][nextC]) {
                        visited[nextR][nextC] = true;
                        q.emplace(make_tuple(nextR, nextC, curNum + 1));
                    }
                }
            }
        }

        return -1;
    };

    cout << bfs() << endl;
    return 0;
}
