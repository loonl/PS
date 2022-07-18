#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n; int x;
    vector<int> answer;
    cin >> x; answer.push_back(x);
    for (int i = 1; i < n; i++) 
    {
        cin >> x;
        auto it = lower_bound(answer.begin(), answer.end(), x);
        if (it == answer.end())
            answer.push_back(x);
        else
            *it = x;
    }

    cout << answer.size() << endl;
    return 0;
}