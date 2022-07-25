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

    ll N; cin >> N;
    ll esa = 0;
    vector<vector<ll>> MAP(N, vector<ll>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    ll sharkR, sharkC;
    ll shark_size = 2, totalPast = 0, ate = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] >= 1 && MAP[i][j] <= 6) {
                esa++;
            }

            else if (MAP[i][j] == 9) {
                sharkR = i; sharkC = j;
              	MAP[i][j] = 0;
            }
        }
    }

    vector<ll> dr = { -1, 1, 0, 0 };
    vector<ll> dc = { 0,  0, -1, 1 };
    set<P> st;
    function<P(ll, ll)> bfs = [&](ll startR, ll startC) -> P {
        queue<tuple<ll, ll, ll>> q;
        q.emplace(make_tuple(startR, startC, 0));
        visited.clear(); visited.assign(N, vector<bool>(N, false));
        st.clear();
        visited[startR][startC] = true;
        ll time = -1;

        while (!q.empty()) {
            auto [curR, curC, curTime] = q.front();
            q.pop();

            auto here = MAP[curR][curC];
            if (here > 0 && here < shark_size) {
               if (time == -1) {
                   time = curTime;
                   st.emplace(make_pair(curR, curC));
               }
               else if (curTime == time)
                   st.emplace(make_pair(curR, curC));
            }

            for (ll i = 0; i < 4; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];
                if (!(nextR < 0 || nextR > N - 1 || nextC < 0 || nextC > N -1)) {
                    if (!visited[nextR][nextC] && MAP[nextR][nextC] <= shark_size) {
                        q.emplace(make_tuple(nextR, nextC, curTime + 1));
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }
      
        if (st.empty())
        	return make_pair(-1, -1);
        MAP[st.begin()->first][st.begin()->second] = 0;
        totalPast += time;
        return make_pair(st.begin()->first, st.begin()->second);
    };

    while (esa > 0) {
        auto x = bfs(sharkR, sharkC);
        sharkR = x.first; sharkC = x.second;

        if (sharkR == -1 && sharkC == -1)
            break;
      
      	ate++;
      	if (ate == shark_size) {
            ate = 0; shark_size++;
      	}
    }

    cout << totalPast << endl;
    return 0;
}
