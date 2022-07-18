#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

bool custom_sort(pair<int, int> a, pair<int, int> b)
{
    int starta, startb, enda, endb;
    starta = a.first, startb = b.first, enda = a.second, endb = b.second;
    if (enda == endb)
        return starta < startb;
    return enda < endb;
}


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    int x, y;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end(), custom_sort);
    int count = 1; int now = vec[0].second;
    for (int i = 1; i < n; i++)
    {
        if (now <= vec[i].first)
        {
            now = vec[i].second;
            count++;
        }
    }

    //for (int i = 0; i < n; i++)
    //{
    //    cout << vec[i].first << " " << vec[i].second << " // ";
    //}

    cout << count << endl;
    return 0;
}