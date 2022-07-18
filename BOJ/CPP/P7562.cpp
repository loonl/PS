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
    vector<ll> dr = {-2, -1, -2, -1, 2, 1, 2, 1};
    vector<ll> dc = {-1, -2, 1,  2,  1, 2,-1, -2};

    ll tc; cin >> tc;
    ll l, startR, startC, endR, endC;
    vector<vector<ll>> ans;
    vector<vector<bool>> visited;

    function<void()> bfs = [&]() -> void {
            queue<P> q;
            q.emplace(make_pair(startR, startC));
            visited[startR][startC] = true;

            while (!q.empty()) {
                auto& [curR, curC] = q.front();
                q.pop();

                if (curR == endR && curC == endC)
                    return;

                for (int i = 0; i < 8; i++) {
                    ll nextR = curR + dr[i];
                    ll nextC = curC + dc[i];
                    if (!(nextR < 0 || nextR > l - 1 || nextC < 0 || nextC > l - 1)) {
                        if (!visited[nextR][nextC]) {
                            visited[nextR][nextC] = true;
                            q.emplace(make_pair(nextR, nextC));
                            ans[nextR][nextC] = ans[curR][curC] + 1;
                        }
                    }
                }
            }
        };

    while (tc--) {
        cin >> l;
        cin >> startR >> startC >> endR >> endC;
        ans.assign(l, vector<ll>(l, 0));
        visited.assign(l, vector<bool>(l, false));

        bfs();
        cout << ans[endR][endC] << endl;
    }
    return 0;
}
