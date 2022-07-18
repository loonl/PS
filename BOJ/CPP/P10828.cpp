#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    stack<int> s;
    string str; int temp;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push") {
            cin >> temp;
            s.push(temp);
        }
        else {
            if (str == "top")  {
                if (s.empty()) {
                    cout << -1 << "\n";
                    continue;
                }
                cout << s.top() << "\n";
            }
            else if (str == "size")
                cout << s.size() << "\n";
            else if (str == "empty")
                cout << s.empty() << "\n";
            else if (str == "pop") {
                if (s.empty()) {
                    cout << -1 << "\n";
                    continue;
                }
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
    return 0;
}