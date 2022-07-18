#include <iostream>
#include <set>
#define endl '\n'
using namespace std;
int n, m;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    set<int> s; int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        auto result = s.find(temp);
        if (result != s.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    return 0;
}