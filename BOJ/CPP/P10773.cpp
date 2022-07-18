#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int temp;
    stack<int> s;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        if (temp == 0) {
            s.pop();
            continue;
        }

        s.push(temp);
    }

    long long hap = 0;
    while (!s.empty()) {
        hap += s.top();
        s.pop();
    }

    cout << hap << endl;
    return 0;
}