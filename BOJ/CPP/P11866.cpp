#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> vec(n, 0);
    for (int i = 1; i <= n; i++)
    {
        vec[i - 1] = i;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int backup = vec[0];
            vec.erase(vec.begin());
            vec.push_back(backup);
        }
        ans.push_back(vec[0]);
        vec.erase(vec.begin());
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans[n - 1] << ">" << endl;
    return 0; 
}