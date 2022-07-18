#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;
ll nozero(ll a)
{
    if (a < 0)
        return 0;
    return a;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<ll> vec(n);
    ll maxval = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] > maxval)
            maxval = vec[i];
    }

    ll start = 0; ll end = maxval;
    ll mid; ll answer;
    while (start <= end)
    {
        mid = (start + end) / 2;
        
        // 계산
        ll shuukaku = 0;
        for (int i = 0; i < n; i++)
        {
            shuukaku += nozero(vec[i] - mid);
        }

        if (shuukaku > m)
        {
            start = mid + 1;
            answer = mid;
        }
        else if (shuukaku < m)
        {
            end = mid - 1;
        }
        else
        {
            answer = mid;
            break;
        }
    }

    cout << answer << endl;
    return 0;
}