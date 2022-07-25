#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
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
    vector<vector<ll>> dp(n, vector<ll>(1 << n, -1));
    vector<vector<ll>> MAP(n, vector<ll>(n, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> MAP[i][j];
        }
    }

    function<ll(ll, ll)> recur = [&](ll cur, ll visited) -> ll {
        ll& ret = dp[cur][visited];
        if (ret != -1)
            return ret;

        // 모든 마을을 방문했다면?
        if (visited == (1 << n) - 1) {
            if (MAP[cur][0] != 0) // 시작점으로 갈 수 있다면?
                return MAP[cur][0];
            return 1000000000; // 시작점으로 갈 수 없다면 불가능한 CASE
        }

        ret = 1000000000;
        for (ll i = 0; i < n; i++) {
            if (visited & (1 << i) || MAP[cur][i] == 0) // 다음에 갈 곳이 이미 방문한 곳이거나, 방문이 불가능하면?
                continue; // 다음 목적지 정찰로 continue
            ret = min(ret, recur(i, visited | (1 << i)) + MAP[cur][i]); // 그게 아니라면 기존의 값 or 다음 방문할 곳 True로 바꿔주고 MAP[cur][i](비용) 더해준 값 중 최소 값 return
        }
        return ret;
    };

    cout << recur(0, 1) << endl;
    return 0;
}
