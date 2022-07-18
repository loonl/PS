#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;

int bsearch(vector<pair<int, int>>& vec, int target)
{
    int mid, high, low;
    low = 0;
    high = vec.size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (vec[mid].first == target)
            return vec[mid].second;
        else if (vec[mid].first > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

bool custom_sort(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;

    map<int, int> m; int number;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        m[number]++;
    }

    vector<pair<int, int>> vec(m.begin(), m.end());

    int tc; cin >> tc;
    int target;
    while (tc--)
    {
        cin >> target;
        int result = bsearch(vec, target);
        
        if (result == -1)
            cout << 0 << endl;
        else
            cout << result << endl;
    }
    return 0;
}