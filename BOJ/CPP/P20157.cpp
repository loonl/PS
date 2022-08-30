#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false); cout.tie(0)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

struct compare {
    bool operator() (const pair<double, ll> a, const pair<double, ll> b) const {
        if (a.second == b.second)
            return a > b;
        return a.second > b.second;
    }
};

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    map<double, ll> mp12_db;
    map<ll, double> mp12_num;
    map<double, ll> mp34_db;
    map<ll, double> mp34_num;
    ll x, y;
    while (n--) {
        cin >> x >> y;
        if (y >= 0) {
            if (y != 0 && x == 0) {
                auto temp = ++mp12_db[MAX];
                mp12_num[temp] = MAX;
            }
            else if (y == 0 && x > 0) {
                auto temp = ++mp12_db[0];
                mp12_num[temp] = 0;
            }
            else if (y == 0 && x < 0) {
                auto temp = ++mp34_db[0];
                mp34_num[temp] = 0;
            }
            else {
                double delta = (double)y / (double)x;
                auto temp = ++mp12_db[delta];
                mp12_num[temp] = delta;
            }
        }
        else {
            if (y != 0 && x == 0) {
                auto temp = ++mp34_db[MAX];
                mp34_num[temp] = MAX;
            }
            else {
                double delta = (double)y / (double)x;
                auto temp = ++mp34_db[delta];
                mp34_num[temp] = delta;
            }
        }
    }

    if (!mp12_num.empty() && !mp34_num.empty())
        cout << max((mp12_num.end()--)->first, (mp34_num.end()--)->first) << endl;
    else if (mp12_num.empty())
        cout << (mp34_num.end()--)->first << endl;
    else
        cout << (mp12_num.end()--)->first << endl;
    return 0;
}
