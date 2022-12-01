#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
ll MOD = 1e9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll tc; cin >> tc;
    bool visited[10001];
    while (tc--) {
        ll start, aim; cin >> start >> aim;
        memset(visited, false, sizeof(visited));
        function<string()> bfs = [&]() -> string {
            queue<pair<ll, string>> q;
            string temp = "";
            q.emplace(make_pair(start, temp));

            while (!q.empty()) {
                auto [cur, curNum] = q.front();
                q.pop();

                if (cur == aim)
                    return curNum;

                ll next1, next2, next3, next4;
                next1 = (cur * 2) % 10000;
                if (!visited[next1]) {
                    visited[next1] = true;
                    q.emplace(make_pair(next1, curNum + "D"));
                }

                next2 = cur - 1;
                if (next2 < 0)
                    next2 = 9999;
                if (!visited[next2]) {
                    visited[next2] = true;
                    q.emplace(make_pair(next2, curNum + "S"));
                }

                next3 = (cur % 1000) * 10 + cur / 1000;
                if (!visited[next3]) {
                    visited[next3] = true;
                    q.emplace(make_pair(next3, curNum + "L"));
                }

                next4 = (cur % 10) * 1000 + (cur / 10);
                if (!visited[next4]) {
                    visited[next4] = true;
                    q.emplace(make_pair(next4, curNum + "R"));
                }
            }
        };

        cout << bfs() << endl;
    }
    return 0;
}
