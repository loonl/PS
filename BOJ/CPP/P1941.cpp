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

    vector<vector<ll>> vec(5, vector<ll>(5, 0)); char x;
    for (ll i = 0; i < 5; i++) {
        for (ll j = 0; j < 5; j++) {
            cin >> x;
            if (x == 'S')
                vec[i][j] = 1;
            else
                vec[i][j] = 2;
        }
    }

    vector<ll> exp2(26, 1);
    for (ll i = 1; i < 26; i++)
        exp2[i] = exp2[i - 1] * 2;

    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1, 1, 0};
    vector<vector<bool>> selected(5, vector<bool>(5, false));
    vector<P> temp;
    set<ll> answers;

    function<ll()> parsed = [&]() -> ll {
        ll ret = 0;
        for (auto& [r, c]: temp)
            ret += exp2[5 * r + c];
        return ret;
    };

    function<ll()> bfs = [&]() -> ll {
        queue<P> q;
        ll ret = 0;
        q.emplace(make_pair(temp[0].first, temp[0].second));
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        visited[temp[0].first][temp[0].second] = true;
        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();

            ret++;

            for (ll i = 0; i < 4; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];
                if (!(nextR < 0 || nextC < 0 || nextR > 4 || nextC > 4)) {
                    if (!visited[nextR][nextC] && selected[nextR][nextC]) {
                        visited[nextR][nextC] = true;
                        q.emplace(make_pair(nextR, nextC));
                    }
                }
            }
        }

        return ret;
    };

    function<void(ll, ll, ll, ll, ll, bool)> back_track = [&](ll count, ll curR, ll curC, ll cntS, ll cntY, bool ok) -> void {
        if (curC == 5) {
            curR++;
            curC = 0;
        }

        if (count == 7) {
            if ((cntS > cntY) && (bfs() == 7))
                answers.emplace(parsed());
            return;
        }

        if (curR == 5 && curC == 0)
            return;

        if (ok) {
            count++;
            selected[curR][curC] = true;
            temp.emplace_back(make_pair(curR, curC));

            if (vec[curR][curC] == 1)
                cntS++;
            else
                cntY++;
        }

        back_track(count, curR, curC + 1, cntS, cntY, true);
        back_track(count, curR, curC + 1, cntS, cntY, false);
        if (ok) {
            selected[curR][curC] = false;
            temp.pop_back();
        }
    };

    back_track(0, 0, 0, 0, 0, true);
    back_track(0, 0, 0, 0, 0, false);
    cout << answers.size() << endl;
    return 0;
}
