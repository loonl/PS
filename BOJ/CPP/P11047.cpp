#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int count = 0;
    while (k > 0)
    {
        auto result = lower_bound(vec.begin(), vec.end(), k);
        if (*result > k)
        {
            result--;
            k -= *result;
            count++;
        }
        else if (*result == k)
        {
            k -= *result;
            count++;
        }
        else if (result == vec.end())
        {
            result--;
            ll x = k / *result;
            count += x;
            k -= x * (*result);
        }
    }
    
    cout << count << endl;
    return 0;
}