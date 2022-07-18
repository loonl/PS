#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
ll absll(ll a)
{
    if (a < 0)
        return -a;
    return a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll k; cin >> k;
    vector<pair<ll, ll>> vec;
    ll x, num;
    for (int i = 0; i < 6; i++)
    {
        cin >> x >> num;
        vec.push_back(make_pair(x, num));
    }

    ll gr = -1, sr = -1; int gr_idx, sr_idx;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((vec[i].first == 1 || vec[i].first == 2)  && gr < vec[i].second)
        {
            gr = vec[i].second;
            gr_idx = i;
        }
        if ((vec[i].first == 3 || vec[i].first == 4) && sr < vec[i].second)
        {
            sr = vec[i].second;
            sr_idx = i;
        }
    }
    ll m_gr, m_sr;
    m_sr = absll(vec[(gr_idx + 7) % 6].second - vec[(gr_idx + 5) % 6].second);
    m_gr = absll(vec[(sr_idx + 7) % 6].second - vec[(sr_idx + 5) % 6].second);
    cout << k * (gr * sr - m_sr * m_gr) << endl;

    return 0;
}