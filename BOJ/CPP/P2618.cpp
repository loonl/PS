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

    ll n, t1, t2, x; cin >> n >> x;
    vector<P> points; points.emplace_back(make_pair(0, 0));
    vector<vector<ll>> dp(x + 1, vector<ll>(x + 1, -1));
    for (ll i = 1; i <= x; i++) {
        cin >> t1 >> t2;
        points.emplace_back(make_pair(t1, t2));
    }

    function<ll(ll, ll)> dist = [&](ll pol1, ll pol2) -> ll {
        if (pol1 == x || pol2 == x)
            return 0;

        if (dp[pol1][pol2] != -1)
            return dp[pol1][pol2];

        auto next = max(pol1, pol2) + 1;
        ll dist1, dist2;

        if (pol1 == 0)
            dist1 = abs(1 - points[next].second) + abs(1 - points[next].first);
        else
            dist1 = abs(points[pol1].first - points[next].first) + abs(points[pol1].second - points[next].second);

        if (pol2 == 0)
            dist2 = abs(n - points[next].second) + abs(n - points[next].first);
        else
            dist2 = abs(points[pol2].first - points[next].first) + abs(points[pol2].second - points[next].second);

        dp[pol1][pol2] = min(dist1 + dist(next, pol2), dist2 + dist(pol1, next));
        return dp[pol1][pol2];
    };

    function<void(ll, ll)> track = [&](ll pol1, ll pol2) -> void {
        if (pol1 == x || pol2 == x)
            return;

        ll next = max(pol1, pol2) + 1;
        ll dist1, dist2;

        if (pol1 == 0)
            dist1 = abs(1 - points[next].second) + abs(1 - points[next].first);
        else
            dist1 = abs(points[pol1].first - points[next].first) + abs(points[pol1].second - points[next].second);

        if (pol2 == 0)
            dist2 = abs(n - points[next].second) + abs(n - points[next].first);
        else
            dist2 = abs(points[pol2].first - points[next].first) + abs(points[pol2].second - points[next].second);

        if (dist1 + dp[next][pol2] < dist2 + dp[pol1][next]) {
            cout << 1 << endl;
            track(next, pol2);
        }
        else {
            cout << 2 << endl;
            track(pol1, next);
        }
    };

    cout << dist(0, 0) << endl;
    track(0, 0);
    
    return 0;
}
