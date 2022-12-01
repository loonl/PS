#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
    //freopen("a.in", "r", stdin);
    string preo, ino;
    while (cin >> preo >> ino) {

        function<void(string, string)> dnc = [&](string pre, string in) -> void {
            if (pre.length() == 0)
                return;
            ll left = find(in.begin(), in.end(), pre[0]) - in.begin(), right = pre.size() - left - 1;
            dnc(pre.substr(1, left), in.substr(0, left));
            dnc(pre.substr(left + 1, right), in.substr(left + 1, right));
            cout << pre[0];
        };

        dnc(preo, ino);
        cout << endl;
    }
    return 0;
}
