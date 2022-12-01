#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

struct compare
{
    bool operator()(const P a, const P b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll tc; cin >> tc; string str;
    while (tc--) {
        ll cost = 0;
        priority_queue<P, vector<P>, compare> pq;
        cin >> str;
        vector<bool> used(str.length(), true);
        for (ll i = 0; i < str.length(); i++) {
            cost += (int)str[i] - 96;
            pq.emplace(make_pair(str[i] - 96, i));
        }

        ll cut; cin >> cut;

        if (cost <= cut) {
            cout << str << endl;
            continue;
        }

        while (!pq.empty()) {
            auto [cost1, idx] = pq.top();
            pq.pop();
            cost -= cost1;
            used[idx] = false;
            if (cost <= cut)
                break;
        }

        for (ll i = 0; i < str.length(); i++) {
            if (used[i])
                cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
