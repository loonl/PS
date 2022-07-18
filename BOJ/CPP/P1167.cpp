#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<pair<ll, ll>>> graph;
vector<bool> visited;
vector<ll> answer;
int v;

void bfs(int start)
{
    queue<ll> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            ll next = graph[cur][i].first;
            ll dis = graph[cur][i].second;
            if (!visited[next])
            {
                answer[next] = answer[cur] + dis;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> v; ll tmp1, tmp2, tmp3;
    graph.assign(v + 1, vector<pair<ll, ll>>());
    visited.assign(v + 1, false);
    answer.assign(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        cin >> tmp1;

        while (true)
        {
            cin >> tmp2;
            if (tmp2 == -1)
                break;
            cin >> tmp3;
            graph[tmp1].emplace_back(make_pair(tmp2, tmp3));
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
            bfs(i);
    }

    int new_start = max_element(answer.begin(), answer.end()) - answer.begin();
    visited.assign(v + 1, false);
    answer.assign(v + 1, 0);
    bfs(new_start);

    cout << *max_element(answer.begin(), answer.end()) << endl;
    return 0;
}