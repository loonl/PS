#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    vector<bool> vec;
    vec.assign(10000, false);
    int dn; string tmp;
    for (int i = 1; i < 10000; i++) {
        dn = i; tmp = to_string(i);
        for (int j = 0; j < tmp.length(); j++) {
            dn += stoi(tmp.substr(j,1));
        }
        if (!vec[dn]) { vec.insert(vec.begin()+dn, true); vec.erase(vec.begin()+dn+1); }
    }
    for (int i = 1; i < vec.size(); i++) {
        if (!vec[i]) { cout << i << endl; }
    }
    return 0;
}