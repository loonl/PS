#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

bool visited_bfs[1001];
bool visited_dfs[1001];
vector<int> graph[10001];

void dfs(int x) {
    visited_dfs[x] = true;
    // todo
    cout << x << " ";
    for (int y : graph[x]) {
        if (!visited_dfs[y])
            dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited_bfs[start] = true;
    
    while(not q.empty()) {
        int x = q.front();
        q.pop();
        // todo
        cout << x << " ";
        
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (not visited_bfs[y]) {
                q.push(y);
                visited_bfs[y] = true;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m, v; cin >> n >> m >> v;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        sort(graph[x].begin(), graph[x].end());
        sort(graph[y].begin(), graph[y].end());
    }

    dfs(v);
    cout << endl;
    bfs(v);
    return 0;
}