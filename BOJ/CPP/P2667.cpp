#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
int n;

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int cur_row, int cur_col, int& count)
{
    if (visited[cur_row][cur_col])
        return;

    visited[cur_row][cur_col] = true;

    // TODO
    count++;

    // to next dfs - 4 directions 
    // left
    if (cur_col != 0)
    {
        if (map[cur_row][cur_col - 1] == 1)
            dfs(map, visited, cur_row, cur_col - 1, count);

    }

    // right
    if (cur_col != n - 1)
    {
        if (map[cur_row][cur_col + 1] == 1)
            dfs(map, visited, cur_row, cur_col + 1, count);
    }

    // up 
    if (cur_row != n - 1)
    {
        if (map[cur_row + 1][cur_col] == 1)
            dfs(map, visited, cur_row + 1, cur_col, count);
    }

    // down
    if (cur_row != 0)
    {
        if (map[cur_row - 1][cur_col] == 1)
            dfs(map, visited, cur_row - 1, cur_col, count);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string str;
    vector<int> answers;
    
    // input
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = stoi(str.substr(j, 1));
        }
    }

    // dfs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                int count = 0;
                dfs(map, visited, i, j, count);

                if (count != 0)
                    answers.emplace_back(count);
            }
        }
    }

    sort(answers.begin(), answers.end());

    // print
    cout << answers.size() << endl;
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
    return 0;
}