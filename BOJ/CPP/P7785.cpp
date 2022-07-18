#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main()
{
    set<string, greater<string>> workplace;
    int n; cin >> n;
    string who, what;
    for (int i = 0; i < n; i++) {
        cin >> who >> what;
        if (what == "enter") {
            workplace.insert(who);
        }
        else if (what == "leave") {
            auto find = workplace.find(who);
            workplace.erase(find);
        }
    }

    for (auto it = workplace.begin(); it != workplace.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}