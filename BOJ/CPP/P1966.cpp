#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

bool custom_sort(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        int n, num; cin >> n >> num;
        queue<pair<int, int>> q; // 값, 우선순위
        vector<int> priority;
        int temp; 
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            q.push(make_pair(i, temp));
            priority.push_back(temp);
        }

        sort(priority.begin(), priority.end(), custom_sort);

        int count = 0;
        while (not q.empty())
        {
            int val = q.front().first;
            int prior = q.front().second;
            q.pop();

            if (prior == priority[0])
            {
                count++;
                priority.erase(priority.begin());
                if (val == num)
                {
                    cout << count << endl;
                    break;
                }
                continue;
            }

            q.push(make_pair(val, prior));
        }
    }

    return 0;
}