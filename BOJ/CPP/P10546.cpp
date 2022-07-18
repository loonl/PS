#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    int n; cin >> n;
    string a;
    multiset<string> marathoners;
    for (int i = 0; i < n; i++) {
        cin >> a;
        marathoners.insert(a);
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        auto find = marathoners.find(a);
        marathoners.erase(find);
    }

    cout << *(marathoners.begin()) << endl;

    return 0;
}