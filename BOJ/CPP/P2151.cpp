#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
string s[50];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0, 0, 1, -1 };
int main()
{
    int start = -1, end = -1;
    vector<pair<int, int>> v;
    cin >> N;
    vector<vector<int>> temp(N, vector<int>(N, 0));
    int num = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
        for (int j = 0; j < N; ++j) {
            if (s[i][j] == '#') {
                v.push_back({ i,j });
                if (start == -1) {
                    start = num;
                }
                else {
                    end = num;
                }
                temp[i][j] = num;
                num++;
            }
            if (s[i][j] == '!') {
                v.push_back({ i,j });
                temp[i][j] = num;
                num++;
            }
        }
    }
    
    vector<vector<bool>> adj(num, vector<bool>(num, 0));
    for (int i = 0; i < v.size(); ++i)
    {
        int y = v[i].first;
        int x = v[i].second;

        for (int j = 0; j < 4; ++j) {
            int ny = y + dy[j];
            int nx = x + dx[j];
            while (0 <= ny && ny < N && 0 <= nx && nx < N) {

                if (s[ny][nx] == '*') break;

                // adj에 넣기
                if (s[ny][nx] == '!' || s[ny][nx] == '#') {
                    adj[i][temp[ny][nx]] = 1;
                }

                ny += dy[j];
                nx += dx[j];
            }
        }
    }
    vector<int> d(num, - 1);
    queue<int> q;
    q.push(start);
    d[start] = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < num; ++i)
        {
            bool there = adj[x][i];
            if (there && d[i] == -1) {
                q.push(i);
                d[i] = d[x] + 1;
            }
        }
    }

    cout << d[end] - 1 << "\n";
    return 0;



}