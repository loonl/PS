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
    ll tc; cin >> tc;
    deque<ll> q;
    string cmd; ll t1;
    while (tc--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> t1;
            q.push_back(t1);
        }
        else if (cmd == "front") {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << -1 << endl;
        }
        else if (cmd == "back") {
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << -1 << endl;
        }
        else if (cmd == "size")
            cout << q.size() << endl;
        else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop_front();
            }
            else
                cout << -1 << endl;
        }
        else if (cmd == "empty")
            cout << q.empty() << endl;
    }
    return 0;
}
