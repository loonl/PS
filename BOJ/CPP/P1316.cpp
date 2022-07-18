#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int m; cin >> m; string a; int cnt= 0; string cut; string lastcut; bool isgroup;
    vector<string> vec;
    for (int i = 0; i < m; i++) {
        cin >> a;  vec.clear(); lastcut = a.substr(0,1); vec.push_back(lastcut); bool inside; isgroup = true;
        for (int j = 1; j < a.length(); j++) {
            cut = a.substr(j,1); inside = false;
            for (int k = 0; k < vec.size(); k++) { if (vec[k] == cut) { inside = true; }}
            if (!inside) { vec.push_back(cut); lastcut = cut; }
            else if (inside) { if (cut != lastcut) { isgroup = false; break; }}
        }
        if  (isgroup) { cnt++; }
    }

    cout << cnt << endl;
    return 0;
}