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
    ll tc; cin >> tc; string t1;
    while (tc--) {
        cin >> t1;
        vector<bool> selected(124, false);
        ll cnt = 0, days = 1, idx = 0;
        while (idx < t1.length()) {
            if (!selected[t1[idx]]) {
                if (cnt == 3) {
                    cnt = 0;
                    selected.clear();
                    selected.assign(124, false);
                    days++;
                }
                else {
                    selected[t1[idx]] = true;
                    cnt++;
                    idx++;
                }
            }
            else {
                idx++;
            }
        }

        cout << days << endl;
    }
    return 0;
}
