#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

bool custom_sort(tuple<char, ll, ll> a, tuple<char, ll, ll> b) {
    return get<1>(a) < get<1>(b);
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    map<char, vector<ll>> dic;
    for (ll i = 65; i <= 90; i++) {
        vector<ll> temp(13, 0);
        dic[(char)i] = temp;
    }

    ll n; cin >> n;
    string str;
    vector<bool> used(91, false);
    vector<bool> cannot_be_0(91, false);
    for (ll i = 0; i < n; i++) {
        cin >> str;

        ll pivot = str.length();

        for (ll j = 0; j < str.length(); j++) {
            used[str[j]] = true;
            dic[str[j]][pivot]++;
            pivot--;
        }

        cannot_be_0[str[0]] = true;
    }

    vector<pair<ll, char>> values;
    for (auto it = dic.begin(); it != dic.end(); it++) {
        if (used[it->first]) {
            ll val = 0;
            for (ll i = 1; i <= 12; i++)
                val += pow(10, i - 1) * (it->second)[i];
            values.emplace_back(make_pair(val, it->first));
        }
    }


    sort(values.begin(), values.end(), greater<>());
    vector<tuple<char, ll, ll>> numbers;
    ll num = 9;
    for (ll i = 0; i < values.size(); i++) {
        auto [val, alpha] = values[i];
        numbers.emplace_back(make_tuple(alpha, num, val));
        num--;
    }

    sort(numbers.begin(), numbers.end(), custom_sort);

    ll idx = 0;
    while (get<1>(numbers[idx]) == 0 && cannot_be_0[get<0>(numbers[idx])]) {
        swap(get<1>(numbers[idx]), get<1>(numbers[idx + 1]));
        if (cannot_be_0[get<0>(numbers[idx + 1])])
            idx++;
    }

    ll ans = 0;
    for (ll i = 0; i < numbers.size(); i++) {
        auto [alp, num1, num2] = numbers[i];
        ans += num1 * num2;
    }
    cout << ans << endl;
    return 0;
}
