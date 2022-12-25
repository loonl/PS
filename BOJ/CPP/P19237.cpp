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
ll MOD = 1e9+7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n, m, smellLast; cin >> n >> m >> smellLast;
    vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
    vector<vector<P>> smell(n + 1, vector<P>(n + 1)); // first : remaining time, second : owner of smell, 
    vector<T> curInfo(m + 1);// first - r, second - c, third = heading direction
    vector<bool> dead(m + 1, false);
    vector<vector<vector<ll>>> prior(m + 1, vector<vector<ll>>(5, vector<ll>(5, 0)));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> vec[i][j];
            if (vec[i][j] != 0) {
                smell[i][j] = make_pair(smellLast, vec[i][j]);
                curInfo[vec[i][j]] = make_tuple(i, j, -1);
            }
        }
    }

    ll t1;
    for (ll i = 1; i <= m; i++) {
        cin >> t1;
        get<2>(curInfo[i]) = t1;
    }

    for (ll shark = 1; shark <= m; shark++) {
        for (ll j = 1; j <= 4; j++) {
            for (ll k = 1; k <= 4; k++)
                cin >> prior[shark][j][k];
        }
    }

    function<P(ll, ll, ll)> cal = [&](ll r, ll c, ll dir) -> P {
        switch (dir) {
            case 1:
                r--;
                break;
            case 2:
                r++;
                break;
            case 3:
                c--;
                break;
            case 4:
                c++;
                break;
        }

        return make_pair(r, c);
    };

    function<bool(ll, ll)> isok = [&](ll r, ll c) -> bool {
        if (r >= 1 && r <= n && c >= 1 && c <= n)
            return true;
        return false;
    };

    function<bool(ll, ll, ll)> isBlank = [&](ll r, ll c, ll direction) -> bool {
        auto [newR, newC] = cal(r, c, direction);
        r = newR, c = newC;

        if (isok(r, c)) {
            if (smell[r][c].first == 0)
                return true;
            else
                return false;
        }
        else
            return false;
    };

    function<bool(ll, ll, ll, ll)> isMySmell = [&](ll shark, ll r, ll c, ll direction) -> bool {
        auto [newR, newC] = cal(r, c, direction);
        r = newR, c = newC;

        if (isok(r, c)) {
            if (smell[r][c].first != 0 && smell[r][c].second == shark)
                return true;
            else
                return false;
        }
        else
            return false;
    };

    ll left = m, time = 0;
    while (time <= 1000 && left > 1) {
        time++;
        vector<vector<vector<ll>>> temp(n + 1, vector<vector<ll>>(n + 1, vector<ll>()));

        for (ll shark = 1; shark <= m; shark++) {
            if (dead[shark])
                continue;

            auto [curR, curC, dir] = curInfo[shark];

            vector<ll> blank, mySmell;
            for (ll i = 1; i <= 4; i++) {
                ll nextDir = prior[shark][dir][i];
                if (isBlank(curR, curC, nextDir))
                    blank.emplace_back(nextDir);
                else {
                    if (isMySmell(shark, curR, curC, nextDir))
                        mySmell.emplace_back(nextDir);
                }
            }

            if (blank.empty()) {
                auto [nextR, nextC] = cal(curR, curC, mySmell[0]);
                curInfo[shark] = make_tuple(nextR, nextC, mySmell[0]);
                temp[nextR][nextC].emplace_back(shark);
            }
            else {
                auto [nextR, nextC] = cal(curR, curC, blank[0]);
                curInfo[shark] = make_tuple(nextR, nextC, blank[0]);
                temp[nextR][nextC].emplace_back(shark);
            }
        }

        // calculate dead sharks
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (temp[i][j].size() >= 2) {
                    sort(temp[i][j].begin(), temp[i][j].end());
                    for (ll k = 1; k < temp[i][j].size(); k++) {
                        dead[temp[i][j][k]] = true;
                        left--;
                    }
                }
            }
        }

        // subtract smell footsteps after moving
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (smell[i][j].first > 0) {
                    smell[i][j].first--;
                    if (smell[i][j].first == 0)
                        smell[i][j].second = 0;
                }
            }
        }

        // make new smell footsteps
        for (ll shark = 1; shark <= m; shark++) {
            if (dead[shark])
                continue;

            auto [curR, curC, __] = curInfo[shark];
            smell[curR][curC] = make_pair(smellLast, shark);
        }
    }
    
    // print
    if (time > 1000)
        cout << -1 << endl;
    else
        cout << time << endl;
    return 0;
}