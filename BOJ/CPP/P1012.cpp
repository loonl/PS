#include <iostream>
#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
int m, n;

void dfs(vector<vector<int>>& vec, vector<vector<bool>>& visited, int cur_row, int cur_col)
{
    visited[cur_row][cur_col] = true;

    // to next dfs
    if (cur_row != 0)
    {
        if (!visited[cur_row - 1][cur_col] && vec[cur_row - 1][cur_col] == 1)
            dfs(vec, visited, cur_row - 1, cur_col);
    }

    if (cur_row != n - 1)
    {
        if (!visited[cur_row + 1][cur_col] && vec[cur_row + 1][cur_col] == 1)
            dfs(vec, visited, cur_row + 1, cur_col);
    }

    if (cur_col != 0)
    {
        if (!visited[cur_row][cur_col - 1] && vec[cur_row][cur_col - 1] == 1)
            dfs(vec, visited, cur_row, cur_col - 1);
    }

    if (cur_col != m - 1)
    {
        if (!visited[cur_row][cur_col + 1] && vec[cur_row][cur_col + 1] == 1)
            dfs(vec, visited, cur_row, cur_col + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        int k; cin >> m >> n >> k;
        vector<vector<int>> vec(n, vector<int>(m, 0));
        int r, c;
        for (int i = 0; i < k; i++)
        {
            cin >> c >> r;
            vec[r][c] = 1;
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vec[i][j] == 1 && !visited[i][j])
                {
                    dfs(vec, visited, i, j);
                    count++;
                }
            }
        }

        cout << count << endl;
    }
}