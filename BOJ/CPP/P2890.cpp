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

    ll r, c; cin >> r >> c; c -= 2;
    vector<vector<ll>> vec(r + 1, vector<ll>(c + 1, 0));
    char t1;
    for (ll i = 1; i <= r; i++) {
        cin >> t1; assert(t1 == 'S');
        for (ll j = 1; j <= c; j++) {
            cin >> t1;
            if (t1 == '.')
                vec[i][j] = 0;
            else
                vec[i][j] = t1 - '0';
        }

        cin >> t1; assert(t1 == 'F');
    }

    vector<P> place(9); // place, team no.
    for (ll i = 0; i < 9; i++)
        place[i].second = i + 1;

    for (ll i = 1; i <= r; i++) {
        ll streak = 0, team = 0, cur = -1;
        for (ll j = 1; j <= c; j++) {
            if (vec[i][j] != 0) {
                team = vec[i][j];
                streak++;

                if (streak == 3)
                    cur = j;
            }
        }

        if (team != 0)
            place[team - 1].first = cur;
    }
    vector<ll> ranks(10, 0);
    sort(place.begin(), place.end(), greater<>());
    auto it = place.begin();
    ll curC = c + 1;

    ll rank = 1;
    while (it != place.end() && curC >= 3) {
        curC--;

        bool isthere = false;
        if (it->first == curC)
            isthere = true;

        while (it != place.end() && it->first == curC) {
            ranks[it->second] = rank;
            it++;
        }

        if (isthere)
            rank++;
    }

    for (ll i = 1; i <= 9; i++)
        cout << ranks[i] << endl;
    return 0;
}