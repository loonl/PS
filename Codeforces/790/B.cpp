#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    string str;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (min > vec[i])
                min = vec[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += vec[i] - min;
        }

        cout << ans << endl;
    }

    return 0;
}