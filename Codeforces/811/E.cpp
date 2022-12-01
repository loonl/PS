#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    while (tc--)
    {
        ll n; cin >> n;
        vector<ll> vec(n, 0);
        vector<ll> tp(20, 0);
        tp[1] = tp[2] = tp[4] = tp[8] = tp[13] = tp[16] = tp[17] = tp[19] = 1;
        tp[3] = tp[6] = tp[7] = tp[9] = tp[11] = tp[12] = tp[14] = tp[18] = 2;
        tp[0] = tp[15] = 3;
        tp[5] = tp[10] = 4;

        bool type1 = false, type2 = false, type3 = false, type4 = false;
        for (ll i = 0; i < n; i++) {
            cin >> vec[i];
        }

        bool no = false;
        ll pivot;
        for (ll i = 0; i < n; i++) {
            ll modl = vec[i] % 20;
            if (tp[modl] == 1) type1 = true;
            else if (tp[modl] == 2) type2 = true;
            else if (tp[modl] == 3) type3 = true;
            else if (tp[modl] == 4) type4 = true;

            if (type3 || type4) {
                if (modl == 5 || modl == 15)
                    pivot = vec[i] + 5;
                else
                    pivot = vec[i];
            }

            if ((type1 && type2) || (type1 && type3) || (type1 && type4) || (type2 && type3) || (type2 && type4) || (type3 && type4)) {
                no = true;
                break;
            }
        }

        if (no)
            cout << "No" << endl;
        else {
            if (type3 || type4) {
                bool no2 = false;
                for (ll i = 0; i < n; i++) {
                    ll cmp;
                    if (vec[i] % 10 == 5)
                        cmp = vec[i] + 5;
                    else
                        cmp = vec[i];

                    if (cmp != pivot) {
                        no2 = true;
                        break;
                    }
                }

                if (no2)
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            }

            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
