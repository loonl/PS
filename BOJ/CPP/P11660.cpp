#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, tc; cin >> n >> tc;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    int val;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != 1)
                vec[i][j] = vec[i][j - 1] + map[i][j];
            else
                vec[i][j] = map[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != 1)
                vec[i][j] += vec[i - 1][j];
        }
    }   

    int r1, r2, c1, c2;
    while (tc--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << vec[r2][c2] - vec[r1 - 1][c2] - vec[r2][c1 - 1] + vec[r1 - 1][c1 - 1] << endl;
    }
    return 0;
}