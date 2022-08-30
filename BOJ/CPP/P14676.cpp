#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    set<ll> ans;
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<ll> entry(n + 1, 0);
    vector<ll> ok;
    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        entry[t2]++;
    }

    vector<ll> nums(n + 1, 0);
    for (ll i = 0; i < k; i++) {
        cin >> t1 >> t2;
        if (t1 == 1) {
            if (entry[t2] == 0) {
                nums[t2]++;
                if (nums[t2] == 1) {
                    for (ll i = 0; i < graph[t2].size(); i++)
                        entry[graph[t2][i]]--;
                }
            }
            else {
                cout << "Lier!" << endl;
                exit(0);
            }
        }
        else {
            if (nums[t2] > 0) {
                nums[t2]--;
                if (nums[t2] == 0) {
                    for (ll i = 0; i < graph[t2].size(); i++)
                        entry[graph[t2][i]]++;
                }
            }
            else {
                cout << "Lier!" << endl;
                exit(0);
            }
        }
    }

    cout << "King-God-Emperor" << endl;
    return 0;
}
