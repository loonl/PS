#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;

bool ascend(vector<int>& vec)
{
    int val = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (val > vec[i])
            return false;
        val = vec[i];
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    if (ascend(vec))
    {
        cout << "Yes" << endl;
        exit(0);
    }
    vector<vector<int>> group;
    for (int i = 0; i < k; i++)
    {
        vector<int> temp;
        for (int j = i; j < n; j += k)
        {
            temp.emplace_back(vec[j]);
        }
        group.emplace_back(temp);
    }

    // sort
    for (int i = 0; i < k; i++)
    {
        sort(group[i].begin(), group[i].end());
    }

    vector<int> result; int sz = 0;
    int cursor = 0; int index = 0;
    while (sz < n)
    {
        sz++;
        result.emplace_back(group[cursor][index]);
        cursor++;
        if (cursor == k)
        {
            cursor = 0;
            index++;
        }
    }

    if (ascend(result))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}