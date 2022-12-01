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
    ll tc; cin >> tc;
    while (tc--) {
        ll n, k; cin >> n >> k;
        vector<ll> st(n+1, 0);
        map<ll, vector<ll>> mp;
        for (ll i = 1; i <= n; i++) {
            cin >> st[i];
            mp[st[i]].emplace_back(i);
        }
        ll a, b;
        while (k--) {
            cin >> a >> b;
            if (mp[a].empty() || mp[b].empty()) {
                cout << "NO" << endl;
                continue;
            }
            auto itB = mp[b].end() - 1; ll pivot = mp[a][0];
            bool flag = false;
            while (itB != mp[b].end()) {
                if (pivot < *itB) {
                    cout << "YES" << endl;
                    flag = true;
                    break;
                }
                else if (pivot > *itB) {
                    itB++;
                }
            }

            if (!flag)
                cout << "NO" << endl;
        }
    }
    return 0;
}
