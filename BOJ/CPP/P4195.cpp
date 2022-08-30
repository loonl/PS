#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
map<string, string> parent;
map<string, ll> num;

string do_find(string x) {
    if (parent[x] == x)
        return x;

    return parent[x] = do_find(parent[x]);
}

void do_union(string x, string y) {
    string px = do_find(x);
    string py = do_find(y);

    if (px != py) {
        parent[px] = py;
        num[py] += num[px];
    }
}

ll do_cnt(string x) {
    if (parent[x] == x)
        return num[x];

    return do_cnt(parent[x]);
}


int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    ll n;
    string t1, t2;
    while (tc--) {
        parent.clear(); num.clear();
        cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> t1 >> t2;

            if (parent[t1] == "") {
                parent[t1] = t1;
                num[t1] = 1;
            }
            if (parent[t2] == "") {
                parent[t2] = t2;
                num[t2] = 1;
            }

            do_union(t1, t2);

            cout << do_cnt(t1) << endl;
        }
    }
    return 0;
}
