#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, tc; cin >> n >> tc;
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        if (i != 1)
            vec[i] += vec[i - 1];
    }

    int st, ed;
    while (tc--)
    {
        cin >> st >> ed;
        cout << vec[ed] - vec[st - 1] << endl;
    }
    return 0;
}