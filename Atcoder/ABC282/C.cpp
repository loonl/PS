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
    queue<char> inside, outside;
    ll n; cin >> n;
    char t1; bool insideQuote = false;
    for (ll i = 0; i < n; i++) {
        cin >> t1;
        if (t1 == '\"') {
            inside.emplace(t1);
            if (insideQuote) {
                insideQuote = false;
                inside.emplace('!');
            }
            else {
                insideQuote = true;
                outside.emplace('!');
            }
        }
        else if (t1 == ',') {
            if (!insideQuote)
                outside.emplace('.');
            else
                inside.emplace(',');
        }
        else {
            if (insideQuote)
                inside.emplace(t1);
            else
                outside.emplace(t1);
        }
    }

    // print
    bool isOut = true;
    while (!outside.empty() || !inside.empty()) {
        if (isOut) {
            while (!outside.empty() && outside.front() != '!') {
                cout << outside.front();
                outside.pop();
            }

            if (!outside.empty()) {
                outside.pop();
                isOut = false;
            }
        }
        else {
            while (!inside.empty() && inside.front() != '!') {
                cout << inside.front();
                inside.pop();
            }

            if (!inside.empty()) {
                inside.pop();
                isOut = true;
            }
        }
    }
    return 0;
}