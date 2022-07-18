#include <iostream>
#include <vector>
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
    ll n, m; cin >> n >> m;
    vector<ll> vec(n); ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        s += vec[i];
    }

    if (s < m)
    {
        cout << 0 << endl;
        exit(0);
    }

    int idx1 = 0, idx2 = 0;
    int answer = n + 1; ll hap = vec[0];
    while (idx1 <= idx2 && idx2 < n)
    {
        if (hap < m)
        {
            idx2++;
            hap += vec[idx2];
        }
        else if (hap >= m)
        {
            answer = min(idx2 - idx1 + 1, answer);
            hap -= vec[idx1];
            idx1++;
        }
    }

    cout << answer << endl;
    return 0;
}