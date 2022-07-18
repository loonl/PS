#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, k;

void bfs(vector<bool>& visited, int pos, vector<int>& nums)
{
    queue<int> q;
    visited[pos] = true;
    q.push(pos);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        // TODO
        if (current == k) 
            return;

        // to next bfs
        if (2 * current <= 100000)
        {
            if (!visited[2 * current])
            {
                nums[2 * current] = nums[current] + 1;
                visited[2 * current] = true;
                q.push(2 * current);
            }
        }
        if (!visited[current + 1])
        {
            nums[current + 1] = nums[current] + 1;
            visited[current + 1] = true;
            q.push(current + 1);
        }

        if (current != 0)
        {
            if (!visited[current - 1])
            {
                nums[current - 1] = nums[current] + 1;
                visited[current - 1] = true;
                q.push(current - 1);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    if (n >= k)
    {
        cout << n - k << endl;
        exit(0);
    }

    vector<bool> visited(100000);
    vector<int> nums(100000, 0);
    bfs(visited, n, nums);
    cout << nums[k] << endl;
    return 0;
}