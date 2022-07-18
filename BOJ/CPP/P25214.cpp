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
    vector<ll> vec(n);
    ll maxi = LLONG_MIN; ll mini = LLONG_MAX;
    int maxi_idx = -1; int mini_idx = -1;
    ll max_cha = 0; ll temp_max_cha = 0;
    for (int i = 0; i < n; i++)
    {
        bool done = false;
        cin >> vec[i];

        // 갱신
        if (maxi < vec[i] && i >= maxi_idx)
        {
            maxi = vec[i];
            maxi_idx = i;
        }
        if (mini > vec[i] && i >= mini_idx)
        {
            mini = vec[i];
            mini_idx = i;
        }


        // 위에 걸리지 않는다면
        if (maxi_idx < mini_idx)
        {
            ll value = (vec[i] - mini) > (max_cha) ? vec[i] - mini : max_cha;
            if (value > temp_max_cha)
                temp_max_cha = value;
            else if (value < temp_max_cha)
                value = temp_max_cha;

            cout << value << " ";
        }

        else if (maxi_idx >= mini_idx)
        {
            max_cha = maxi - mini;
            cout << max_cha << " ";
        }
    }
    cout << endl;
    return 0;
}