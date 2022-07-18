#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m, h;

void bfs(vector<vector<vector<int>>>& map, vector<vector<vector<bool>>>& visited, vector<vector<vector<int>>>& nums)
{
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (map[i][j][k] == 1)
                {
                    visited[i][j][k] = true;
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    while (!q.empty())
    {
        int z = get<0>(q.front()), r = get<1>(q.front()), c = get<2>(q.front());
        q.pop();

        vector<int> dh = {-1,1,0,0,0, 0};
        vector<int> dr = {0,0,-1,1,0, 0};
        vector<int> dc = {0,0, 0,0,-1,1};
        for (int i = 0; i < 6; i++)
        {
            int nxth = z + dh[i], nxtr = r + dr[i], nxtc = c + dc[i];
            if (!(nxth < 0 || nxth > h - 1 || nxtr < 0 || nxtr > n - 1 || nxtc < 0 || nxtc > m - 1))
            {
                if (map[nxth][nxtr][nxtc] == 0 && !visited[nxth][nxtr][nxtc])
                {
                    visited[nxth][nxtr][nxtc] = true;
                    map[nxth][nxtr][nxtc] = 1;
                    nums[nxth][nxtr][nxtc] = nums[z][r][c] + 1;
                    q.push(make_tuple(nxth, nxtr, nxtc));
                }
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> m >> n >> h;
    vector<vector<vector<int>>> map(h, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> map[i][j][k];
            }
        }
    }

    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(n, vector<bool>(m, false)));
    vector<vector<vector<int>>> nums(h, vector<vector<int>>(n, vector<int>(m, 0)));

    bfs(map, visited, nums);

    int maxval = -1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (nums[i][j][k] == 0 && map[i][j][k] == 0)
                {
                    cout << -1 << endl;
                    exit(0);
                }
                if (nums[i][j][k] > maxval)
                    maxval = nums[i][j][k];
            }
        }
    }
    cout << maxval << endl;
    return 0;
}