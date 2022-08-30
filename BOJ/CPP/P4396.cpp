#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<vector<ll>> mp1(n, vector<ll>(n, 0));
    vector<vector<ll>> mp2(n, vector<ll>(n, 0));
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    bool boom = false;
    char x;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> x;
            if (x == '*')
                mp1[i][j] = 1;
            else
                mp1[i][j] = 0;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> x;
            if (x == 'x')
                mp2[i][j] = 1;
        }
    }

    vector<ll> dr = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<ll> dc = {-1,0,1,  -1, 1, -1, 0,  1};

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (mp2[i][j] == 0) {
                ans[i][j] = -1;
                continue;
            }

            if (mp2[i][j] != 0 && mp1[i][j] == 1)
                boom = true;

            ll num = 0;
            for (ll k = 0; k < 8; k++) {
                ll nextR = i + dr[k], nextC = j + dc[k];
                if (!(nextR < 0 || nextR > n - 1 || nextC < 0 || nextC > n -1)) {
                    if (mp1[nextR][nextC] == 1)
                        num++;
                }
            }
            ans[i][j] = num;
        }
    }

fin:
    if (boom) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (mp1[i][j] == 1)
                    cout << "*";
                else if (ans[i][j] == -1)
                    cout << ".";
                else
                    cout << ans[i][j];
            }
            cout << endl;
        }
    }
    else {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (ans[i][j] == -1)
                    cout << ".";
                else
                    cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
