#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<char> vec(m, 0);
    for(ll i = 0; i < m; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    function<void(ll, ll, bool, string)> back_track = [&](ll count, ll idx, bool use, string word) -> void {
        if (idx > m - 1)
            return;

        if (use) {
            count++;
            word.push_back(vec[idx]);
        }

        if (count == n) {
            ll x = 0, y = 0;
            for (ll i = 0; i < n; i++) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                    x++;
                else
                    y++;
            }
            if (x >= 1 && y >= 2)
                cout << word << endl;
            return;
        }

        back_track(count, idx + 1, true, word);
        back_track(count, idx + 1, false, word);
    };

    back_track(0, 0, true,  "");
    back_track(0, 0, false, "");
    return 0;
}
