#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m;

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

void bfs(vector<vector<int>>& map, vector<vector<vector<bool>>>& visited, vector<vector<vector<int>>>& nums)
{
    vector<int> dr = { -1, 1, 0, 0 };
    vector<int> dc = { 0,  0, -1, 1 };
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = true;
    while (!q.empty())
    {
        int r = get<0>(q.front()), c = get<1>(q.front()), x = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nxtr = r + dr[i], nxtc = c + dc[i];
            if (!(nxtr < 0 || nxtr > n - 1 || nxtc < 0 || nxtc > m - 1))
            {
                if (map[nxtr][nxtc] == 1 && x == 0 && !visited[nxtr][nxtc][1])
                {
                    visited[nxtr][nxtc][1] = true;
                    q.push(make_tuple(nxtr, nxtc, 1));
                    nums[nxtr][nxtc][1] = nums[r][c][0] + 1;
                }

                if (map[nxtr][nxtc] == 0 && !visited[nxtr][nxtc][x])
                {
                    visited[nxtr][nxtc][x] = true;
                    q.push(make_tuple(nxtr, nxtc, x));
                    nums[nxtr][nxtc][x] = nums[r][c][x] + 1;
                }
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    char input;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input;
            map[i][j] = (int)input - (int)'0';
        }
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    vector<vector<vector<int>>> nums(n, vector<vector<int>>(m, vector<int>(2, 0)));
    bfs(map, visited, nums);

    if (nums[n - 1][m - 1][0] == 0 && nums[n - 1][m - 1][1] == 0)
    {
        if (n == 1 && m == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    else if (nums[n - 1][m - 1][0] == 0)
        cout << nums[n - 1][m - 1][1] + 1 << endl;
    else if (nums[n - 1][m - 1][1] == 0)
        cout << nums[n - 1][m - 1][0] + 1 << endl;
    else
        cout << min(nums[n - 1][m - 1][0] + 1, nums[n - 1][m - 1][1] + 1) << endl;
    return 0;
}