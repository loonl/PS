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
    vector<vector<ll>> vec(8, vector<ll>(8, 0));
    for (ll i = 0; i < 8; i++) {
        for (ll j = 0; j < 8; j++)
            cin >> vec[i][j];
    }

    char cmd; cin >> cmd;
    if (cmd == 'U') {
        for (ll i = 0; i < 8; i++) {
            vector<ll> temp, temp2;
            for (ll j = 0; j < 8; j++) {
                if (vec[j][i] != 0)
                    temp.emplace_back(vec[j][i]);
            }

            ll prev = -1;
            for (ll j = 0; j < temp.size(); j++) {
                if (prev == -1) {
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
                else if (temp[j] == prev) {
                    temp2.emplace_back(prev * 2);
                    prev = -1;
                }
                else {
                    temp2.emplace_back(prev);
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
            }

            for (ll j = 0; j < temp2.size(); j++)
                vec[j][i] = temp2[j];

            for (ll j = temp2.size(); j < 8; j++)
                vec[j][i] = 0;
        }
    }
    else if (cmd == 'D') {
        for (ll i = 0; i < 8; i++) {
            vector<ll> temp, temp2;
            for (ll j = 7; j >= 0; j--) {
                if (vec[j][i] != 0)
                    temp.emplace_back(vec[j][i]);
            }

            ll prev = -1;
            for (ll j = 0; j < temp.size(); j++) {
                if (prev == -1) {
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
                else if (temp[j] == prev) {
                    temp2.emplace_back(prev * 2);
                    prev = -1;
                }
                else {
                    temp2.emplace_back(prev);
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
            }

            for (ll j = 0; j < temp2.size(); j++)
                vec[7 - j][i] = temp2[j];

            for (ll j = temp2.size(); j < 8; j++)
                vec[7 - j][i] = 0;
        }
    }
    else if (cmd == 'L') {
        for (ll i = 0; i < 8; i++) {
            vector<ll> temp, temp2;
            for (ll j = 0; j < 8; j++) {
                if (vec[i][j] != 0)
                    temp.emplace_back(vec[i][j]);
            }

            ll prev = -1;
            for (ll j = 0; j < temp.size(); j++) {
                if (prev == -1) {
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
                else if (temp[j] == prev) {
                    temp2.emplace_back(prev * 2);
                    prev = -1;
                }
                else {
                    temp2.emplace_back(prev);
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
            }

            for (ll j = 0; j < temp2.size(); j++)
                vec[i][j] = temp2[j];

            for (ll j = temp2.size(); j < 8; j++)
                vec[i][j] = 0;
        }
    }
    else {
        for (ll i = 0; i < 8; i++) {
            vector<ll> temp, temp2;
            for (ll j = 7; j >= 0; j--) {
                if (vec[i][j] != 0)
                    temp.emplace_back(vec[i][j]);
            }

            ll prev = -1;
            for (ll j = 0; j < temp.size(); j++) {
                if (prev == -1) {
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
                else if (temp[j] == prev) {
                    temp2.emplace_back(prev * 2);
                    prev = -1;
                }
                else {
                    temp2.emplace_back(prev);
                    prev = temp[j];
                    if (j == temp.size() - 1)
                        temp2.emplace_back(prev);
                }
            }

            for (ll j = 0; j < temp2.size(); j++)
                vec[i][7 - j] = temp2[j];

            for (ll j = temp2.size(); j < 8; j++)
                vec[i][7 - j] = 0;
        }
    }

    for (ll i = 0; i < 8; i++) {
        for (ll j = 0; j < 8; j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    return 0;
}