#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
using namespace std;
int n;

void swap(map<int, int>& m, int idx1, int idx2)
{
    int temp = m[idx1];
    m[idx1] = m[idx2];
    m[idx2] = temp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> n >> tc;
    map<int, int> m; // value, index
    map<int, int> m2; // index, value
    for (int i = 1; i <= n; i++)
    {
        m[i] = i;
        m2[i] = i;
    }

    while (tc--)
    {
        int x; cin >> x;
        int idx = m[x];
        if (idx == n)
        {
            // swap with left
            swap(m, m2[idx], m2[idx - 1]);
            swap(m2, idx - 1, idx);
        }
        else
        {
            // swap with right
            swap(m, m2[idx], m2[idx + 1]);
            swap(m2, idx, idx + 1);
        }

    }

    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        cout << it->second << " ";
    }
    return 0;
}