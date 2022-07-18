#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m;

void bfs(vector<vector<int>>& vec, vector<vector<bool>>& visited, int r, int c, vector<vector<int>>& nums)
{
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while (!q.empty())
    {
        r = q.front().first, c = q.front().second;
        q.pop();
        
        // TODO
        if (r == n - 1 && c == m - 1)
            return;

        // to next bfs
        if (r != 0)
        {
            if (!visited[r - 1][c] && vec[r - 1][c] == 1)
            {
                q.push(make_pair(r - 1, c));
                nums[r - 1][c] = nums[r][c] + 1;
                visited[r - 1][c] = true;
            }
        }

        if (r != n - 1)
        {
            if (!visited[r + 1][c] && vec[r + 1][c] == 1)
            {
                q.push(make_pair(r + 1, c));
                nums[r + 1][c] = nums[r][c] + 1;
                visited[r + 1][c] = true;
            }
        }

        if (c != 0)
        {
            if (!visited[r][c - 1] && vec[r][c - 1] == 1)
            {
                q.push(make_pair(r, c - 1));
                nums[r][c - 1] = nums[r][c] + 1;
                visited[r][c - 1] = true;
            }
        }

        if (c != m - 1)
        {
            if (!visited[r][c + 1] && vec[r][c + 1] == 1)
            {
                q.push(make_pair(r, c + 1));
                nums[r][c + 1] = nums[r][c] + 1;
                visited[r][c + 1] = true;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    char x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            vec[i][j] = x - '0';
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> nums(n, vector<int>(m, 1));
    bfs(vec, visited, 0, 0, nums);
    cout << nums[n - 1][m - 1] << endl;
    return 0;
}