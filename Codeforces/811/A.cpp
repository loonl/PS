#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    while (tc--)
    {
        ll n, h, m;
        cin >> n >> h >> m;
        vector<P> alarms;
        ll t1, t2;
        for (ll i = 0; i < n; i++) {
            cin >> t1 >> t2;
            alarms.emplace_back(make_pair(t1,t2));
        }

        sort(alarms.begin(), alarms.end());
        auto found = lower_bound(alarms.begin(), alarms.end(), make_pair(h, m));
        ll ansH, ansM;
        if (found == alarms.end()) {
            ansH = alarms[0].first + 24 - h;
            ansM = alarms[0].second - m;
            if (ansM < 0) {
                ansM += 60;
                ansH--;
            }
        }
        else {
            ansH = found->first - h;
            ansM = found->second - m;
            if (ansM < 0) {
                ansM += 60;
                ansH--;
            }
        }

        cout << ansH << " " << ansM << endl;
    }
    return 0;
}
