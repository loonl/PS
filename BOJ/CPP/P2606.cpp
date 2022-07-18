#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;
set<int> infected;

void dfs(vector<bool>& visited, vector<vector<int>>& graph, int current)
{
    visited[current] = true;
    
    // TODO
    infected.insert(current);

    for (int next : graph[current])
    {
        if (!visited[next])
            dfs(visited, graph, next);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int coms, pairs; cin >> coms >> pairs;
    vector<vector<int>> graph(coms + 1, vector<int>());
    vector<bool> visited(coms + 1, false);

    int a, b;
    for (int i = 0; i < pairs; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    
    dfs(visited, graph, 1);

    cout << infected.size() - 1 << endl;
    return 0;
}