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

    ll n; cin >> n;
    vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++)
            cin >> vec[i][j];
    }

    if (n == 1) {
        cout << vec[1][1] << endl;
        exit(0);
    }

    ll maxBlock = -1;
    function<void(ll)> back_track = [&](ll number) -> void {
        if (number == 5) {
            ll maxHere = 0;
            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j <= n; j++) {
                    if (maxHere <= vec[i][j])
                        maxHere = vec[i][j];
                }
            }

            if (maxHere > maxBlock)
                maxBlock = maxHere;

            return;
        }

        vector<vector<ll>> backup = vec;

        // up
        {
            for (ll i = 1; i <= n; i++) {

                vector<ll> temp, final(1, -1);
                for (ll j = 1; j <= n; j++) {
                    if (vec[j][i] != 0)
                        temp.emplace_back(vec[j][i]);
                }

                for (ll j = 1; j < temp.size(); j++) {
                    if (temp[j - 1] == temp[j]) {
                        temp[j - 1] *= 2;
                        temp[j] = 0;
                    }
                }

                for (ll j = 0; j < temp.size(); j++) {
                    if (temp[j] != 0)
                        final.emplace_back(temp[j]);
                }

                for (ll j = 1; j < final.size(); j++)
                    vec[j][i] = final[j];

                for (ll j = final.size(); j <= n; j++)
                    vec[j][i] = 0;
            }

            back_track(number + 1);
            vec = backup;
        }

        // down
        {
            for (ll i = 1; i <= n; i++) {

                vector<ll> temp, final;
                for (ll j = n; j >= 1; j--) {
                    if (vec[j][i] != 0)
                        temp.emplace_back(vec[j][i]);
                }

                for (ll j = 1; j < temp.size(); j++) {
                    if (temp[j - 1] == temp[j]) {
                        temp[j - 1] *= 2;
                        temp[j] = 0;
                    }
                }

                for (ll j = 0; j < temp.size(); j++) {
                    if (temp[j] != 0)
                        final.emplace_back(temp[j]);
                }

                for (ll j = n; j >= n - final.size() + 1; j--)
                    vec[j][i] = final[n - j];

                for (ll j = n - final.size(); j >= 1; j--)
                    vec[j][i] = 0;
            }

            back_track(number + 1);
            vec = backup;
        }

        // left
        {
            for (ll i = 1; i <= n; i++) {
                vector<ll> temp, final(1, -1);
                for (ll j = 1; j <= n; j++) {
                    if (vec[i][j] != 0)
                        temp.emplace_back(vec[i][j]);
                }

                for (ll j = 1; j < temp.size(); j++) {
                    if (temp[j - 1] == temp[j]) {
                        temp[j - 1] *= 2;
                        temp[j] = 0;
                    }
                }

                for (ll j = 0; j < temp.size(); j++) {
                    if (temp[j] != 0)
                        final.emplace_back(temp[j]);
                }

                for (ll j = 1; j < final.size(); j++)
                    vec[i][j] = final[j];

                for (ll j = final.size(); j <= n; j++)
                    vec[i][j] = 0;
            }

            back_track(number + 1);
            vec = backup;
        }

        // right
        {
            for (ll i = 1; i <= n; i++) {

                vector<ll> temp, final;
                for (ll j = n; j >= 1; j--) {
                    if (vec[i][j] != 0)
                        temp.emplace_back(vec[i][j]);
                }

                for (ll j = 1; j < temp.size(); j++) {
                    if (temp[j - 1] == temp[j]) {
                        temp[j - 1] *= 2;
                        temp[j] = 0;
                    }
                }

                for (ll j = 0; j < temp.size(); j++) {
                    if (temp[j] != 0)
                        final.emplace_back(temp[j]);
                }

                for (ll j = n; j >= n - final.size() + 1; j--)
                    vec[i][j] = final[n - j];

                for (ll j = n - final.size(); j >= 1; j--)
                    vec[i][j] = 0;
            }

            back_track(number + 1);
            vec = backup;
        }
    };

    back_track(0);
    cout << maxBlock << endl;
    return 0;
}
