#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
void bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent)
{
    queue<int> q;
    q.emplace(1);
    visited[1] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int next : graph[curr])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                parent[next] = curr;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    bfs(graph, visited, parent);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << endl;
    }
    
    return 0;
}