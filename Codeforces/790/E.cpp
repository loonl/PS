#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        int n, q; cin >> n >> q;
        multiset<int, greater<int>> s;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            s.insert(temp);
        }

        vector<int> vec(s.begin(), s.end());

        // make into pSum
        for (int i = 1; i < n; i++)
        {
            vec[i] += vec[i - 1];
        }

        int maxval = vec[n - 1];

        // queries
        while (q--)
        {
            int target; cin >> target;
            if (target > maxval)
            {
                cout << -1 << endl;
                continue;
            }

            int st = 0, en = n - 1;
            auto it = lower_bound(vec.begin(), vec.end(), target);
            cout << it - vec.begin() + 1 << endl;
        }
    }

    return 0;
}