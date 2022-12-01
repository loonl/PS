#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> map; map.push_back(vector<int>());
    for (int i = 1; i <= n; i++)
    {
        vector<int> vec; vec.push_back(0);
        for (int j = 1; j <= i; j++)
        {
            if (j == i || j == 1)
                vec.push_back(1);
            else
                vec.push_back(map[i - 1][j - 1] + map[i - 1][j]);
        }
        map.push_back(vec);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= map[i].size() - 1; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}