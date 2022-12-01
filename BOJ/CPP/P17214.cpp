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
    string temp = "";
    vector<P> info;
    if (str == "0") {
        cout << 'W' << endl;
        exit(0);
    }

    for (ll i = 0; i < str.length(); i++) {
        auto cur = str[i];
        if (cur == 'x') {
            ll tmp = stoi(temp) / 2;
            info.emplace_back(make_pair(tmp, 2));
            temp = "";
        }
        else if (cur != '+')
            temp.push_back(cur);
    }

    if (temp != "")
        info.emplace_back(make_pair(stoi(temp), 1));

    string ans = "";
    if (!info.empty()) {
        auto [gye, cha] = info[0];
        if (abs(gye) != 1)
            ans += to_string(gye);
        else if (gye == -1)
            ans += "-";
        for (ll i = 0; i < cha; i++)
            ans.push_back('x');
    }

    for (ll i = 1; i < info.size(); i++) {
        auto [gye, cha] = info[i];
        if (abs(gye) != 1) {
            if (gye > 0) {
                ans = ans + "+" + to_string(gye);
                ans.push_back('x');
            }
            else {
                ans = ans + to_string(gye);
                for (ll i = 0; i < cha; i++)
                    ans.push_back('x');
            }
        }
        else {
            if (gye > 0) {
                ans = ans + "+";
                for (ll i = 0; i < cha; i++)
                    ans.push_back('x');
            }
            else {
                ans = ans + "-";
                for (ll i = 0; i < cha; i++)
                    ans.push_back('x');
            }
        }
    }

    ans = ans + "+W";
    cout << ans << endl;
    return 0;
}