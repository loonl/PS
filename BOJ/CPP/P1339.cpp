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
    map<char, vector<ll>> dic;
    for (ll i = 65; i <= 90; i++) {
        vector<ll> temp(13, 0);
        dic[(char)i] = temp;
    }

    ll n; cin >> n;
    string str;
    vector<bool> used(91, false);
    for (ll i = 0; i < n; i++) {
        cin >> str;

        ll pivot = str.length();
        for (ll j = 0; j < str.length(); j++) {
            used[str[j]] = true;
            dic[str[j]][pivot]++;
            pivot--;
        }
    }

    multiset<ll, greater<ll>> value;
    for (auto it = dic.begin(); it != dic.end(); it++) {
        if (used[it->first]) {
            ll val = 0;
            for (ll i = 1; i <= 12; i++)
                val += pow(10, i - 1) * (it->second)[i];
            value.emplace(val);
        }
    }

    ll ans = 0; ll piv = 9;
    for (auto it = value.begin(); it != value.end(); it++) {
        ans += piv * (*it);
        piv--;
    }

    cout << ans << endl;
    return 0;
}
