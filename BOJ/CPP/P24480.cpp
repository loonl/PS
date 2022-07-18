#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;
map<int, int> answer;
int now = 1;

void dfs(vector<bool>& visited, vector<vector<int>>& graphs, int current)
{
    visited[current] = true;
    // TODO
    answer[current] = now;
    now++;

    for (int next : graphs[current])
    {
        if (!visited[next])
            dfs(visited, graphs, next);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int start, end;
    int n, m, r; cin >> n >> m >> r;
    vector<vector<int>> graphs(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);

    // first set of answer
    for (int i = 1; i <= n; i++)
    {
        answer[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        graphs[start].emplace_back(end);
        graphs[end].emplace_back(start);
    }

    // sort
    for (int i = 1; i <= n; i++)
    {
        sort(graphs[i].begin(), graphs[i].end(), greater<>());
    }

    // dfs start
    dfs(visited, graphs, r);

    // print answer
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}