#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll tc; cin >> tc; cin.ignore();
    map<char, ll> code;
    map<ll, char> code2;
    code[' '] = 0;
    for (ll i = 97; i <= 122; i++)
        code[(char)i] = i - 96;

    for (auto it = code.begin(); it != code.end(); it++)
        code2[it->second] = it->first;

    while (tc--) {
        string str, cmd, sen, res = "";
        getline(cin, str);
        cmd = str.substr(0, 1), sen = str.substr(2, str.length() - 2);
        vector<ll> vec(sen.length(), 0);

        for (ll i = 0; i < sen.length(); i++)
            vec[i] = code[sen[i]];

        if (cmd == "e") {
            for (ll i = 1; i < sen.length(); i++)
                vec[i] += vec[i - 1];

            for (ll i = 1; i < sen.length(); i++)
                vec[i] %= 27;

            for (ll i = 0; i < sen.length(); i++)
                res.push_back(code2[vec[i]]);
        }

        if (cmd == "d") {
            for (ll i = 1; i < sen.length(); i++) {
                while (vec[i] < vec[i - 1])
                    vec[i] += 27;
            }

            for (ll i = sen.length() - 1; i >= 1; i--)
                vec[i] = vec[i] - vec[i - 1];

            for (ll i = 0; i < sen.length(); i++)
                res.push_back(code2[vec[i]]);
        }

        cout << res << endl;
    }
    return 0;
}
