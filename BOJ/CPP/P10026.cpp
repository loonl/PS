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
    ll n; cin >> n;
    vector<vector<char>> nor(n, vector<char>(n, '0'));
    vector<vector<char>> jr(n, vector<char>(n, '0'));
    vector<vector<bool>> visitedN(n, vector<bool>(n, false));
    vector<vector<bool>> visitedJ(n, vector<bool>(n, false));
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str; assert(str.length() == n);
        for (int j = 0; j < n; j++) {
            nor[i][j] = str[j];
            if (str[j] == 'B')
                jr[i][j] = 'B';
            else
                jr[i][j] = 'R';
        }
    }

    vector<ll> dr = {-1, 1, 0, 0};
    vector<ll> dc = {0,  0,-1, 1};
    ll ans_N = 0, ans_J = 0;
    function<void(ll, ll)> Nbfs = [&](ll stR, ll stC) -> void {
        queue<P> q;
        q.emplace(make_pair(stR, stC));
        visitedN[stR][stC] = true;
        char color = nor[stR][stC];
        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();
            for (ll i = 0; i < 4; i++) {
                ll nxtR = curR + dr[i], nxtC = curC + dc[i];
                if (!(nxtR < 0 || nxtR > n - 1 || nxtC < 0 || nxtC > n - 1)) {
                    if (!visitedN[nxtR][nxtC] && nor[nxtR][nxtC] == color) {
                        visitedN[nxtR][nxtC] = true;
                        q.emplace(make_pair(nxtR, nxtC));
                    }
                }
            }
        }
    };

    function<void(ll, ll)> Jbfs = [&](ll stR, ll stC) -> void {
        queue<P> q;
        q.emplace(make_pair(stR, stC));
        visitedJ[stR][stC] = true;
        char color = jr[stR][stC];
        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();
            for (ll i = 0; i < 4; i++) {
                ll nxtR = curR + dr[i], nxtC = curC + dc[i];
                if (!(nxtR < 0 || nxtR > n - 1 || nxtC < 0 || nxtC > n - 1)) {
                    if (!visitedJ[nxtR][nxtC] && jr[nxtR][nxtC] == color) {
                        visitedJ[nxtR][nxtC] = true;
                        q.emplace(make_pair(nxtR, nxtC));
                    }
                }
            }
        }
    };

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <n; j++) {
            if (!visitedN[i][j]) {
                ans_N++;
                Nbfs(i, j);
            }

            if (!visitedJ[i][j]) {
                ans_J++;
                Jbfs(i, j);
            }
        }
    }

    cout << ans_N << " " << ans_J << endl;
    return 0;
}
