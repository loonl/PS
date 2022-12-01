#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    vector<vector<bool>> visited(500, vector<bool>(500, false));
    ll n; cin >> n; string str; cin >> str;
    function<void(ll, ll, ll, ll)> dfs = [&](ll curR, ll curC, ll curIDX, ll dir) -> void {
        if (curIDX == str.length() + 1)
            return;

        if (dir < 0)
            dir += 4;

        if (!visited[curR][curC])
            visited[curR][curC] = true;

        auto cur = str[curIDX];
        if (cur == 'F') {
            if (dir == 0)
                dfs(curR - 1, curC, curIDX + 1, dir);
            else if (dir == 1)
                dfs(curR, curC - 1, curIDX + 1, dir);
            else if (dir == 2)
                dfs(curR + 1, curC, curIDX + 1, dir);
            else
                dfs(curR, curC + 1, curIDX + 1, dir);
        }
        else if (cur == 'L')
                dfs(curR, curC, curIDX + 1, (dir + 1) % 4);
        else
            dfs(curR, curC, curIDX + 1, (dir - 1) % 4);
    };

    dfs(250, 250, 0, 2);
    ll minR = MAX, minC = MAX, maxR = -1, maxC = -1;
    for (ll i = 0; i < visited.size(); i++) {
        for (ll j = 0; j < visited[i].size(); j++) {
            if (visited[i][j]) {
                if (minR > i)
                    minR = i;
                if (maxR < i)
                    maxR = i;
                if (minC > j)
                    minC = j;
                if (maxC < j)
                    maxC = j;
            }
        }
    }

    for (ll i = minR; i <= maxR; i++) {
        for (ll j = minC; j <= maxC; j++) {
            if (visited[i][j])
                cout << '.';
            else
                cout << '#';
        }
        cout << endl;
    }
    return 0;
}