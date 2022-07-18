#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;

ll max(ll a, ll b) {
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n; cin >> n;
    ll temp;
    vector<ll> vec;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.emplace_back(temp);
    }

    ll acc[301];
    acc[0] = vec[0];
    acc[1] = vec[0] + vec[1];
    acc[2] = max(vec[0] + vec[2], vec[1]+vec[2]);
    for (int i = 3; i < vec.size(); i++) {
        acc[i] = max(acc[i - 3] + vec[i - 1] + vec[i], acc[i - 2] + vec[i]);
    }

    cout << acc[n - 1] << endl;
    return 0;
}