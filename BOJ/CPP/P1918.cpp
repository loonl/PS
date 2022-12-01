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
ll MOD = 1e9+7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    string str, ans = ""; cin >> str;
    stack<pair<char, ll>> opers;
    for (ll i = 0; i < str.length(); i++) {
        char temp = str[i];

        if (isalpha(temp)) {
            ans.push_back(temp);
            continue;
        }
        else {
            if (temp == '+' || temp == '-') {
                if (!opers.empty()) {
                    while (!opers.empty() && opers.top().second >= 1) {
                        ans.push_back(opers.top().first);
                        opers.pop();
                    }
                }

                opers.emplace(make_pair(temp, 1));
            }
            else if (temp == '*' || temp == '/') {
                if (!opers.empty()) {
                    while (!opers.empty() && opers.top().second >= 2) {
                        ans.push_back(opers.top().first);
                        opers.pop();
                    }
                }

                opers.emplace (make_pair (temp, 2));
            }
            else if (temp == '(')
                opers.emplace(make_pair(temp, 0));
            else {
                while (opers.top().first != '(') {
                    ans.push_back(opers.top().first);
                    opers.pop();
                }
                opers.pop();
            }
        }
    }

    while (!opers.empty()) {
        ans.push_back(opers.top().first);
        opers.pop();
    }

    cout << ans << endl;
    return 0;
}