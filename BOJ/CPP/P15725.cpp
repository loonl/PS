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
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    string str; cin >> str;
    vector<P> info;
    string temp = "";
    for (ll i = 0; i < str.length(); i++) {
        char cur = str[i];
        if (cur == 'x') {
            if (temp != "" && temp != "-" && temp != "+")
                info.emplace_back(make_pair(stoll(temp), 0));
            else if (temp == "" || temp == "+")
                info.emplace_back(make_pair(1, 0));
            else
                info.emplace_back(make_pair(-1, 0));
            temp = "";
        }
        else
            temp += cur;
    }

    if (info.empty())
        cout << 0 << endl;
    else {
        ll ans = 0;
        for (ll i = 0; i < info.size(); i++) {
            ans += info[i].first;
            assert(info[i].second == 0);
        }

        cout << ans << endl;
    }
    return 0;
}