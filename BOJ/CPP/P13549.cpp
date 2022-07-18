#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define PD pair<double, double>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll n, k; cin >> n >> k;
    vector<bool> visited(100001, false);

    if (n >= k) {
        cout << n - k << endl;
        exit(0);
    }

    function<ll()> bfs = [&]() -> ll {
        queue<tuple<ll, ll>> q;
        q.emplace(make_tuple(n, 0));
        visited[n] = true;
        while (!q.empty()) {
            auto [curloc, cur$] = q.front();
            q.pop();

            if (curloc == k)
                return cur$;

            if (curloc * 2 <= min(2 * k, (ll)100000)) {
                if (!visited[curloc * 2]) {
                    q.emplace(make_tuple(curloc * 2, cur$));
                    visited[curloc * 2] = true;
                }
            }

            if (curloc - 1 >= 0) {
                if (!visited[curloc - 1]) {
                    q.emplace(make_tuple(curloc - 1, cur$ + 1));
                    visited[curloc - 1] = true;
                }
            }

            if (curloc + 1 <= min(2 * k, (ll)100000)) {
                if (!visited[curloc + 1]) {
                    q.emplace(make_tuple(curloc + 1, cur$ + 1));
                    visited[curloc + 1] = true;
                }

            }
        }
    };

    cout << bfs() << endl;
    return 0;
}
