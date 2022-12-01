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
vector<bool> used;
string str;
set<string> printed;

bool custom_sort(pair<char, ll> a, pair<char, ll> b) {
    if (a.first == b.first)
        return a < b;
    return a.first < b.first;
}

void recur(ll idx) {
    used[idx] = true;
    string temp = "";
    for (ll i = 0; i < str.length(); i++) {
        if (used[i])
            temp.push_back(str[i]);
    }
    if (!printed.contains(temp)) {
        cout << temp << endl;
        printed.emplace(temp);
    }
    else return;

    char pivot = '[', next = -1;

    for (ll i = idx + 1; i < str.length(); i++) {
        if (pivot > str[i]) {
            pivot = str[i];
            next = i;
        }
    }

    if (next != -1)
        recur(next);

    pivot = '[';
    ll next2 = -1;
    for (ll i = 0; i < idx; i++) {
        if (pivot > str[i] && !used[i]) {
            pivot = str[i];
            next2 = i;
        }
    }

    if (next2 != -1)
        recur(next2);
}


int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, t1, t2; cin >> n;
    vector<P> vec;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        vec.emplace_back(make_pair(t1,t2));
    }
    sort(vec.begin(), vec.end());

    ll st = vec[0].first, ed = vec[0].second, ans = 0;
    for (ll i = 1; i < n; i++) {
        auto [st2, ed2] = vec[i];
        if (ed >= st2)
            ed = max(ed, ed2);
        else {
            ans += ed - st;
            st = st2, ed = ed2;
        }
    }

    ans += ed - st;
    cout << ans;
    return 0;
}