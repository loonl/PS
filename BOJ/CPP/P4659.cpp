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
    string str;
    set<char> m = {'a','e','i','o','u'};
    while (cin >> str) {
        if (str == "end")
            break;

        bool ok = true, isMoe = false;
        char prev = ' ';
        ll streak = 0, cntM = 0, cntJ = 0;
        for (ll i = 0; i < str.length(); i++) {
            auto cur = str[i];
            if (prev == cur) {
                if (!(cur == 'o' || cur == 'e')) {
                    ok = false;
                    break;
                }
            }

            prev = cur;

            if (isMoe) {
                if (m.contains(cur)) {
                    streak++;
                    cntM++;
                }
                else {
                    isMoe = false;
                    streak = 1;
                    cntJ++;
                }
            }
            else {
                if (m.contains(cur)) {
                    isMoe = true;
                    streak = 1;
                    cntM++;
                }
                else {
                    streak++;
                    cntJ++;
                }
            }

            if (streak >= 3) {
                ok = false;
                break;
            }
        }

        if (cntM == 0)
            ok = false;

        if (ok)
            cout << "<" << str << ">" << " is acceptable." << endl;
        else
            cout << "<" << str << ">" << " is not acceptable." << endl;
    }

    return 0;
}