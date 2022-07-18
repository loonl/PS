#include <iostream>
#include <vector>
using namespace std;

void pick(int range, int num, vector<int> picked, vector<bool> picked_, int insert) {
    
    picked.push_back(insert);
    picked_[insert] = true;

    if (num == picked.size()) {
        for (int i = 0; i < picked.size(); i++) {
            cout << picked[i] << " ";
        }
        cout << "\n"; return;
    }

    for (int i = 1; i <= range; i++) {
        if (picked_[i]) { continue; }
        pick(range, num, picked, picked_, i);
    }

}

int main(){
    cin.tie(NULL); cout.tie(NULL); cin.sync_with_stdio(false);
    int a,b; cin >> a >> b; vector<int> vec; vec.clear(); vector<bool> picked;
    picked.assign(9, false);

    for (int i = 1; i <= a; i++) {
        pick(a, b, vec, picked, i);
    }
    return 0;
}