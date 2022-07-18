#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> oil(n);
    vector<ll> dist(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> oil[i];
    }

    ll mini = LLONG_MAX; ll answer = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (mini > oil[i])
            mini = oil[i];
        answer += mini * dist[i];
    }

    cout << answer << endl;
    return 0;
}