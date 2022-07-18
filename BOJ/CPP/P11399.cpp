#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    ll answer = 0;
    int idx = 0; ll freq = n;
    while (idx < n && freq > 0)
    {
        answer += vec[idx] * freq;
        idx++; freq--;
    }

    cout << answer << endl;
    return 0;
}