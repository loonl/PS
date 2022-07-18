#include <iostream>
#include <climits>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
ll min(ll a, ll b)
{
    if (a > b)
        return b;
    return a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;

    ll start = 1; ll end = k;
    ll mid; 
    ll result = LLONG_MAX;
    while (start <= end)
    {
        mid = (start + end) / 2;
        ll count = 0;
        ll limit = n;

        for (ll i = 1; i <= n; i++)
        {
            count += min(mid / i, n);
        }

        if (count >= k)
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else if (count < k)
        {
            start = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}