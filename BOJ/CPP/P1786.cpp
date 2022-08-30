#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
ll MOD = 1e9 + 7;

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    string t1, t2;
    getline(cin, t1);
    getline(cin, t2);
    if (t1.length() < t2.length()) {
        cout << 0 << endl;
        exit(0);
    }

    vector<ll> pows(1000001, 0);
    pows[0] = 1;
    for (ll i = 1; i < t2.length(); i++)
        pows[i] = pows[i - 1] * 97 % MOD;


    ll hasht1 = 0, hasht2 = 0;
    for (ll i = 0; i < t2.length(); i++) {
        hasht1 = (hasht1 + t1[i] * pows[t2.length() - 1 - i]) % MOD;
        hasht2 = (hasht2 + t2[i] * pows[t2.length() - 1 - i]) % MOD;
    }

    vector<ll> loc;
    if (hasht1 == hasht2)
        loc.emplace_back(1);

    for (ll i = 1; i <= (t1.length() - t2.length()); i++) {
        hasht1 = (hasht1 - t1[i - 1] * pows[t2.length() - 1]) % MOD;
        if (hasht1 < 0)
            hasht1 += MOD;

        hasht1 = hasht1 * 97 % MOD;
        hasht1 = (hasht1 + t1[i + t2.length() - 1]) % MOD;
        if (hasht1 == hasht2)
            loc.emplace_back(i + 1);
    }

    cout << loc.size() << endl;
    for (const auto& ele: loc)
        cout << ele << " ";

    return 0;
}
