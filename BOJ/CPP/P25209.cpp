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
    vector<vector<char>> vec(3 * n + 1, vector<char>(3 * m + 1, 'X'));
    for (ll i = 1; i <= 3 * n; i++) {
        for (ll j = 1; j <= 3 * m; j++)
            cin >> vec[i][j];
    }

    vector<vector<ll>> newmap(n + 1, vector<ll>(m + 1, 0));
    vector<string> patterns = {"", ".........", "#########", "#..##.###", "###.##..#", "#####.#..", "..#.#####", "####0####", "####1####", "####2####", "####3####", "####4####" };
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            string temp = "";
            temp.push_back(vec[3 * i - 2][3 * j - 2]);
            temp.push_back(vec[3 * i - 2][3 * j - 1]);
            temp.push_back(vec[3 * i - 2][3 * j]);
            temp.push_back(vec[3 * i - 1][3 * j - 2]);
            temp.push_back(vec[3 * i - 1][3 * j - 1]);
            temp.push_back(vec[3 * i - 1][3 * j]);
            temp.push_back(vec[3 * i][3 * j - 2]);
            temp.push_back(vec[3 * i][3 * j - 1]);
            temp.push_back(vec[3 * i][3 * j]);
            for (ll k = 1; k < patterns.size(); k++) {
                if (temp == patterns[k]) {
                    newmap[i][j] = -k;
                    break;
                }
            }
        }
    }

    function<bool(ll, ll)> noE = [&](ll r, ll c) -> bool {
        if (!(r < 1 || c < 1 || r > n || c > m))
            return true;
        return false;
    };

    vector<ll> dR = {-1, 0, 0, 1};
    vector<ll> dC = {0, -1, 1, 0};
    function<bool(ll, ll, ll)> isok = [&](ll curR, ll curC, ll aim) -> bool {
        ll cnt = 0;
        for (ll i = 0; i < 4; i++) {
            ll nextR = curR + dR[i], nextC = curC + dC[i];
            if (noE(nextR, nextC)) {
                auto shape = newmap[nextR][nextC];
                if (shape > 100)
                    cnt++;
            }
        }

        if (cnt == aim)
            return true;
        return false;
    };

    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    vector<ll> dr = {0, 0, 1};
    vector<ll> dc = {-1, 1, 0};
    function<void(ll, ll, ll, ll)> dfs_diagonal = [&](ll curR, ll curC, ll flag, ll type) -> void {
        visited[curR][curC] = true;
        newmap[curR][curC] = flag;

        if (type == 1) {
            if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -4)
                dfs_diagonal(curR, curC + 1, flag, 2);
            else {cout << "NO" << endl; exit(0);}

            if (noE(curR + 1, curC) && !visited[curR + 1][curC] && newmap[curR + 1][curC] == -3) {
                if (noE(curR + 1, curC + 1) && !visited[curR + 1][curC + 1] && newmap[curR + 1][curC + 1] == -1)
                    dfs_diagonal(curR + 1, curC, flag, 6);
                else
                    dfs_diagonal(curR + 1, curC, flag, 9);
            }
            else if (noE(curR + 1, curC - 1) && !visited[curR + 1][curC - 1] && newmap[curR + 1][curC - 1] == -5)
                dfs_diagonal(curR + 1, curC - 1, flag, 3);
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 2) {
            if (noE(curR, curC - 1) && newmap[curR][curC - 1] == flag) {}
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 3) {
            if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -1)
                dfs_diagonal(curR, curC + 1, flag, 4);
            else {cout << "NO" << endl; exit(0); }

            if (noE(curR + 1, curC) && !visited[curR + 1][curC] && newmap[curR + 1][curC] == -3) {
                if (noE(curR + 1, curC + 1) && !visited[curR + 1][curC + 1] && newmap[curR + 1][curC + 1] == -6)
                    dfs_diagonal(curR + 1, curC, flag, 9);
                else
                    dfs_diagonal(curR + 1, curC, flag, 6);
            }
            else if (noE(curR + 1, curC - 1) && !visited[curR + 1][curC - 1] && newmap[curR + 1][curC - 1] == -5)
                dfs_diagonal(curR + 1, curC - 1, flag, 3);
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 4) {
            if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -1)
                dfs_diagonal(curR, curC + 1, flag, 4);
            else if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -4)
                dfs_diagonal(curR, curC + 1, flag, 5);
            else if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -6)
                dfs_diagonal(curR, curC + 1, flag, 8);
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 5) {
            if (noE(curR - 1, curC - 1) && newmap[curR - 1][curC - 1] == flag) {}
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 6) {
            if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -1)
                dfs_diagonal(curR, curC + 1, flag, 4);
            else {cout << "NO" << endl; exit(0);}

            if (noE(curR + 1, curC + 1) && !visited[curR + 1][curC + 1] && newmap[curR + 1][curC + 1] == -3) {
                if (noE(curR + 1, curC + 2) && !visited[curR + 1][curC + 2] && newmap[curR + 1][curC + 2] == -6)
                    dfs_diagonal(curR + 1, curC + 1, flag, 9);
                else
                    dfs_diagonal(curR + 1, curC + 1, flag, 6);
            }
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 8) {
            if (noE(curR - 1, curC + 1) && newmap[curR][curC + 1] == flag) {}
            else if (noE(curR - 1, curC) && newmap[curR - 1][curC] == flag) {}
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 9) {
            if (noE(curR, curC + 1) && !visited[curR][curC + 1] && newmap[curR][curC + 1] == -6)
                dfs_diagonal(curR, curC + 1, flag, 10);
            else {cout << "NO" << endl; exit(0);}
        }
        else if (type == 10) {
            if (noE(curR - 1, curC + 1) && newmap[curR - 1][curC + 1] == flag) {}
            else if (noE(curR - 1, curC) && newmap[curR - 1][curC] == flag) {}
            else {cout << "NO" << endl; exit(0);}
        }
    };

    vector<ll> deltaR = {0, 1};
    vector<ll> deltaC = {1, 0};
    function<void(ll, ll, ll)> bfs_rect = [&](ll stR, ll stC, ll flag) -> void {
        queue<P> q;
        q.emplace(make_pair(stR, stC));
        visited[stR][stC] = true;

        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();

            newmap[curR][curC] = -flag;

            for (ll i = 0; i < 2; i++) {
                ll nextR = curR + deltaR[i], nextC = curC + deltaC[i];
                if (noE(nextR, nextC)) {
                    if (!visited[nextR][nextC] && newmap[nextR][nextC] == -1) {
                        q.emplace(make_pair(nextR, nextC));
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }
    };

    ll numbering = 102;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            auto cur = newmap[i][j];
            if (cur == -5 && !visited[i][j]) {
                numbering++;
                dfs_diagonal(i, j, numbering, 1);
            }

            else if (cur == -1 && !visited[i][j]) {
                numbering++;
                bfs_rect(i, j, numbering);
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            auto cur = newmap[i][j];
            if (cur == -7 || cur == -8 || cur == -9 || cur == -10 || cur == -11) {
                visited[i][j] = true;
                ll aim = -cur - 7;
                if (isok(i, j, aim))
                    newmap[i][j] = 100;
                else {cout << "NO" << endl; exit(0);}
            }
            else if (cur == -2)
                visited[i][j] = true;
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (newmap[i][j] == -2) {
                newmap[i][j] = 101;
                visited[i][j] = true;
            }
        }
    }

    bool ans = true, flagA = false;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (!visited[i][j] || abs(newmap[i][j]) < 100) {
                ans = false;
                flagA = true;
                break;
            }
        }
        if (flagA)
            break;
    }

    if (!ans) {cout << "NO" << endl; exit(0);}

    vector<vector<bool>> checked(n + 1, vector<bool>(m + 1, false));
    function<void(ll, ll)> check_rect = [&](ll stR, ll stC) -> void {
        auto pivot = newmap[stR][stC];
        set<ll> garos; ll garo = 0;
        for (ll i = stR; (i <= n) && (newmap[i][stC] < -100); i++) {
            garo = 0;

            if (newmap[i][stC] != pivot) {cout << "NO" << endl; exit(0);}

            for (ll j = stC; j <= m; j++) {
                if (newmap[i][j] != pivot && newmap[i][j] > -100)
                    break;

                else if (newmap[i][j] != pivot && newmap[i][j] < -100) {cout << "NO" << endl; exit(0);}

                checked[i][j] = true;
                garo++;
            }

            garos.emplace(garo);
            if (garos.size() > 1) {cout << "NO" << endl; exit(0);}
        }
    };

    vector<bool> used(10001, false);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (!checked[i][j] && newmap[i][j] < -100) {
                if (!used[-newmap[i][j]]) {
                    used[-newmap[i][j]] = true;
                    check_rect(i, j);
                }
                else {cout << "NO" << endl; exit(0);}
            }
        }
    }


    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
