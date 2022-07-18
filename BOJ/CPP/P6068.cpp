#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;

// 정렬 기준 : 1. 끝 시간 2. 같은건 작업시간 짧은거
bool custom_sort(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return (a.first + a.second < b.first + b.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> todo(n); // (시작해야 되는 시간, 걸리는 시간)
    int x, y; int end_max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y - x < 0)
        {
            cout << -1 << endl;
            exit(0);
        }
        if (end_max < y)
            end_max = y;
        todo[i] = make_pair(y - x, x);
    }

    sort(todo.begin(), todo.end(), custom_sort);

    int first = todo[0].first;

    // check - 일을 진행하고 다음 index의 시작시간보다 크다면 false
    bool yes = false; int value = INT_MAX;
    for (int i = first; i >= 0; i--)
    {
        bool able = true;
        int now = i;
        for (int j = 0; j < n; j++)
        {
            if (now > todo[j].first)
            {
                able = false;
                break;
            }
            now += todo[j].second;
        }

        // final check
        if (now > end_max)
            able = false;

        if (able)
        {
            value = i;
            yes = true;
            break;
        }
    }
    if (!yes)
        cout << -1 << endl;
    else
        cout << value << endl;
    return 0; 
}