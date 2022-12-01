#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str; cin >> str;
    cout << str.substr(str.length() - 2, 2) << endl;
    return 0;
}