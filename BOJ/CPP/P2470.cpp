#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
ll ab(ll x)
{
    ll tmp = x;
    if (tmp < 0)
        tmp = -tmp;
    return tmp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int idx1 = 0, idx2 = n - 1;
    ll mixed = vec[0] + vec[n - 1];
    ll ans1 = vec[0], ans2 = vec[n - 1];
    while (idx1 < idx2)
    {
        ll mix_tmp = vec[idx1] + vec[idx2];
        if (ab(mix_tmp) < ab(mixed))
        {
            mixed = mix_tmp;
            ans1 = vec[idx1], ans2 = vec[idx2];
        }

        if (mix_tmp > 0)
            idx2--;
        else
            idx1++;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}