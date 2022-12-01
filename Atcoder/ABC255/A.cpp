#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
typedef long long ll;
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    vector<vector<int>> vec(2, vector<int>(2)); int r, c;
    cin >> r >> c >> vec[0][0] >> vec[0][1] >> vec[1][0] >> vec[1][1];
    cout << vec[r - 1][c - 1] << endl;
    return 0;
}

