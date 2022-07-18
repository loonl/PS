#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vector<ll> vec(n + 1, 0);
    vector<ll> nmj(m, 0);
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (vec[i] % m == 0)
            count++;
    } 

    for (int i = 1; i <= n; i++)
    {
        nmj[vec[i] % m]++;
    }

    for (int i = 0; i < m; i++)
    {
        count += nmj[i] * (nmj[i] - 1) / 2;
    }

    cout << count << endl;
    return 0;
}