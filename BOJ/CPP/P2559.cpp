#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        if (i != 1)
            vec[i] += vec[i - 1];
    }

    vector<int> chas;
    int temp;
    for (int i = k; i <= n; i++)
    {
        temp = vec[i] - vec[i - k];
        chas.emplace_back(temp);
    }

    cout << *max_element(chas.begin(), chas.end()) << endl;
    return 0;
}