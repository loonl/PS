#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str; cin >> str;
    int len = str.length();
    int z = 6 / len;
    for (int i = 0; i < z; i++) {
        cout << str;
    }
    return 0;
}