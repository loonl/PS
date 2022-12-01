#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
vector<vector<ll>> vec;
struct compare {
    bool operator()(P a, P b) {
        return vec[a.first][a.second] < vec[b.first][b.second];
    }
};

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    vec.assign(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++)
            cin >> vec[i][j];
    }

    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1, 1, 0};
    priority_queue<P, vector<P>, compare> pq;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++)
            pq.emplace(make_pair(i, j));
    }

    function<ll(ll, ll)> dfs = [&](ll curR, ll curC) -> ll {
        if (dp[curR][curC] != -1)
            return dp[curR][curC];

        auto curNum = vec[curR][curC];
        dp[curR][curC] = 1;
        for (ll i = 0; i < 4; i++) {
            ll nextR = curR + dr[i], nextC = curC + dc[i];
            if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > n)) {
                auto nextNum = vec[nextR][nextC];
                if (curNum > nextNum)
                    dp[curR][curC] = max(dp[curR][curC], dfs(nextR, nextC) + 1);
            }
        }

        return dp[curR][curC];
    };

    while (!pq.empty()) {
        auto [r, c] = pq.top();
        pq.pop();
        if (dp[r][c] == -1)
            dfs(r, c);
    }

    ll ans = -1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;

    return 0;
}
