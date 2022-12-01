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
vector<ll> vec;
ll plu, minu, mul, dive, n;
ll maxi = LLONG_MIN, mini = LLONG_MAX;
void back_track(ll cur, ll chose, ll temp) {
    if (cur == n + 1) {
        if (temp > maxi)
            maxi = temp;
        if (temp < mini)
            mini = temp;
        return;
    }

    if (cur != 1) {
        if (chose == 1)
            temp += vec[cur];
        else if (chose == 2)
            temp -= vec[cur];
        else if (chose == 3)
            temp *= vec[cur];
        else if (chose == 4) {
            if (temp < 0) {
                temp = -temp;
                temp /= vec[cur];
                temp = -temp;
            }
            else
                temp /= vec[cur];
        }
    }
    else
        temp = vec[cur];

    if (plu > 0) {
        plu--;
        back_track(cur + 1, 1, temp);
        plu++;
    }

    if (minu > 0)  {
        minu--;
        back_track(cur + 1, 2, temp);
        minu++;
    }

    if (mul > 0) {
        mul--;
        back_track(cur + 1, 3, temp);
        mul++;
    }

    if (dive > 0) {
        dive--;
        back_track(cur + 1, 4, temp);
        dive++;
    }

    else if (cur == n)
        back_track(cur + 1, -1, temp);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    cin >> n;
    vec.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    cin >> plu >> minu >> mul >> dive;
    back_track(1, -1, -1);
    cout << maxi << endl << mini << endl;

    return 0;
}